// The inheritable ship object - used with Ship_d.
// (05-09-00) Written by Chronos.
// Properties that must be set for this to work right:
// arrival_msg          Displayed to everyone outside the ship.
// depart_msg           Displayed to everyone outside the ship.
// get_underway_msg     Displayed to everyone outside the ship.
// get_moored_msg       Displayed to everyone outside the ship.
// underway_msg         Displayed to everyone on the ship.
// moored_msg           Displayed to everyone on the ship.
// home_port            Filename of default port to start in.

#include <mudlib.h>
#include <ships.h>
#include <daemons.h>

inherit OBJECT ;

// Globals.
string *port_list = ({ }) ;
int *port_time= ({ }) ;
int Moored, Port ;              // Port tracks which port we are in.

// Prototypes.
void commission_ship() ;
int move_ship(int x) ;
int query_port() ;
string query_arrival() ;
int query_mins_left() ;                 // Returns -1 if underway.
string query_depart() ;
void tell_ship(string Msg);
object query_start_room() ;
string query_home_port() ;
int query_moored() ;
void moore_ship() ;
void underway() ;

string query_short() {
  string str ; 
  if (Moored) str=capitalize((string)query("name"))+" is moored here.";
  else str = capitalize((string)query("name"))+" is floating near here.";
  return str;
}

int query_port() { return Port ; } 

void create() {
  seteuid(getuid()) ;
  set("short", "@@query_short") ;
  set("ROOM_LIST", ({ }) ) ;
  set("name", "generic") ;
  set("moored_msg", @ENDLONG
[ Default Mooring Message ]
ENDLONG
  );
  set("get_underway_msg", @ENDLONG
[ Default Getting Underway Message ]
ENDLONG
  );
  set("get_moored_msg", @ENDLONG
[ Default Getting Moored Message ]
ENDLONG
  );
  set("underway_msg", @ENDLONG
[ Default Underway Message ]
ENDLONG
  );
  set("home_port", "/u/c/chronos/area/rooms/pier1-1") ; //default
  set("arrival_msg", @ENDMSG
[ Default Arrival Message ]
ENDMSG
  );
  set("depart_msg", @ENDMSG
[ Default Departure Message ]
ENDMSG
  );
  set("id", ({ "#SHIP#", "ship" }) ) ;
  set("long", @ENDLONG
A non-descript ship.  It floats, that's about it.
ENDLONG
  );
  set("prevent_get", 1) ;
  set("prevent_insert", 1) ;
  Moored = 1;
  Port = 1;
}

void init() {
  if (!environment(TO)) TO->move(query("home_port")) ;
  if (userp(environment(TO))) TO->move(query("home_port")) ;
  add_action("board_ship", "enter") ;
  add_action("board_ship", "board") ;
  add_action("wiztest", "wiztest") ;
  add_action("look", "look") ;
}


int board_ship(string str) {
  if (!str) {
    write("Board what?\n") ;
    return 1;
  }
  if (!id(str)) {
    write("Board what?\n") ;
    return 1;
  }
  if (query_start_room()) {
    write("You board "+query("name")+".\n") ;
    say(TPN+" boards "+query("name")+".\n") ;
    TP->move_player(query_start_room(), "SNEAK") ;
    message("movement", TPN+" comes aboard.\n",query_start_room(),
      ({ TP }) ) ;
  }
  else write("You cannot board right now.\n");
  return 1;
}

object query_start_room() {
  string *blah;
  object Room;
  blah = query("ROOM_LIST") ;
  if (!blah) return 0;
  Room = find_object_or_load(blah[0]) ;
  if (!Room) return 0;
  return Room ;
}

int query_moored() {
  return Moored ;
}

// Called when the ship enters port.
void moore_ship() {
  Moored = 1;                                   // Set us Moored.
  if (Port==sizeof(port_list)) Port = 0 ;       // Advance our Port
  else Port++;                                  // counter..
  tell_object(environment(TO), query("get_moored_msg")) ; // Tell env a msg.
  tell_ship(query("moored_msg")) ;              // Tell the ship about it.
  call_out("underway", port_time[Port] * 60 ) ; // Start the countdown.
}

// Called when the ship leaves port.
void underway() {
  Moored = 0 ;                                  // Underway..
  tell_object(environment(TO), query("get_underway_msg")) ; // Tell env a msg.
  tell_ship(query("underway_msg")) ;              // Tell the ship about it.
  move_ship(1);
}

void tell_ship(string Msg) {
  int i;
  string *list ;
  list = query("ROOM_LIST") ;
  for(i=0;i<sizeof(list);i++)
    message("movement", Msg, list[i]) ;
}

string query_depart() {
  return (string)query("depart_msg") ;
}

string query_arrival() {
  return (string)query("arrival_msg") ;
}

string query_home_port() {
  return (string)query("home_port") ;
}

// This function loads all the port data and starts up the movement of
// the ship.  :)
void commission_ship() {
  int i ;
  port_list = SHIP_D->query_port_data(file_name(TO)) ;
  port_time = SHIP_D->query_port_time(file_name(TO)) ;
  if (!port_list) port_list = ({ "/d/Ocean/rooms/default_pier",
                                 "/d/Ocean/rooms/default_pier" }) ;
  if (!port_time) {
        for(i=0;i<sizeof(port_list);i++) 
          port_time[i] = random(6) + 2 ;
  }    
  call_out("underway", port_time[0] * 60 ) ;
}

int wiztest() {
  int i;
  if (!wizardp(TP)) return 0;
  for(i=0;i<sizeof(port_list);i++) {
    write("Port #"+i+": "+port_list[i]+"\n") ;
  }
  return 1;
}

string query_current_location() {
  return file_name(environment(TO)) ;
}

// Process the call_out that moves the ship.
/*
string query_mins_left() {
  string str;
  int x;
  x = find_call_out("underway") ;
  if (!x) x = find_call_out("moore_ship") ;
  if (!x) return "Unknown." ;
  str = (x/60)+" minutes ( "+x+" seconds. )\n";
  return str;
}
*/

// Now we move the ship through the "ocean", finally arriving at our
// final destination, which is:  port_list[Port]
int move_ship(int x) {
  object loc_ob ;
  string loc ;
  message("movement", query_depart(), environment(TO) ) ;
  if (x<3) {
    loc = "/d/Ocean/Ocean/ocean"+random(20) ;
    loc_ob = find_object_or_load(loc) ;
    if (!loc_ob) loc_ob = find_object_or_load("/d/Ocean/Ocean/ocean0") ;
    TO->move(loc_ob) ;
    message("movement", query_arrival(), environment(TO)) ;
    call_out("move_ship", 25+random(15), x+1) ;
    return 1;
  }
  loc_ob = find_object_or_load(port_list[Port]) ;
  if (!loc_ob) loc_ob = find_object_or_load(DEFAULT_PIER) ;
  TO->move(loc_ob) ;
  message("movement", query_arrival(), environment(TO) ) ;
  moore_ship();
  return 1;
}

int look(string str) {
  if (str == "at ship" || str=="at "+query("name")) {
        write(query("long")) ;
    say(TPN+" looks at "+query("name")+".\n") ;;
    return 1;
  }
  return 0 ;
  }
