#include <mudlib.h>
#include <path.h>

inherit ROOM ;
inherit DOORS ;

void create() {
   object ob1;

   ::create();
   seteuid(getuid(this_object()));
   call_other(ROOMS+ "mainboard", "main");
 
   set("short", "Questing agency");
   set("long", @Endtext
You are in the Questing agency of Vieillere, where players come to seek
fame and fortune.  On the walls are several screens displaying the many
places that adventurers can visit.  A computer sits on a metal stand
with the words "Quest Listings" displayed on the monitor.  To the north,
a pair of automatic sliding doors lead into the wizzing room.
Endtext
  );
  set("exit_msg", ([
    "north" : "$N leaves through the automatic doors to the north.\n",
  ]) ) ;
  set("item_desc", ([
    "screens" :
      "They display short trailers of the different parts of the world.\n"+
      "Watching them, it feels as if you're in a travel agency.\n",
    "stand" :
      "It is a made of steel.  The stand is somehow attached to the\n"+
      "floor, enabling it to hold the computer safely.\n",
    "computer" :
      "It lists all the quests in the realms.  You can <read> the screen.\n",
    "monitor" :
      "It displays the <Quest Listings> of the realm.  You can <read> them.\n",
    "doors" : "They are connected to a motion sensor.\n",
]) ) ;
  set("light", 1);
  set("exits", ([
    "north" : ROOMS+ "hall2",
    "east" : ROOMS+ "road02",
  ]) ) ;
  set("exit_msg", ([
    "north" : "$N leaves north through the sliding doors.",
  ]) );
  set("pre_exit_func", ([ "north" : "slide_open" ]) );
  create_door("east", "west", "A metal door", "open");
  set("objects", ([
    MOBS+ "sec_drone" : 1,
  ]) ) ;
  reset();
}

void init() {
  add_action ("read_screen", "read") ;
}

int read_screen(string str) {
  if(str!="screen" && str!="listings" && str!="quest listings") {
    notify_fail ("What do you want to read?\n") ;
    return 0 ;
  }
  write ("You browse through the Quests Listings and read:\n"+
"<No available quests online presently.>\n");
  say (TPCN+ " reads the Quest Listings.\n") ;
  return 1 ;
}

void slide_open() {
  write("The doors slide open as you leave north.\n");
  return 0;
}
