#include <config.h>
#include <mudlib.h>

inherit ROOM;

#define TPN this_player()->query("cap_name")

object coffee, wine;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
   set ("short", "A Hot Tub");
  set( "long", @EndText
You are in the hot tub of the wizroom, Nightmask put it here for the
players...er player, Woobie to be exact. Nightmask thought he needed
somewhere else to go when he logged in here. The warm bubbles seem to
oothe and calm you as you sit and relax with a drink.
EndText
);
  set( "exits", ([
      "out" : "/d/Ancients/rooms/wizrm.c",
  ]) );
  set ("item_desc", ([
 ]) );
}

void init() {
   add_action ("Megadeth", "order");
 }

int Megadeth(string str) {
  if (!str) {
     write ("Order what?\n");
   return 1;
  }

 if (str == "wine") {
     write ("The waitress brings you a wine.\n");
     say (TPN +" orders a wine and the waitress brings it.\n");
     wine = clone_object("/u/n/nightmask/private/wine.c");
     wine->move(this_object());
   return 1;
 }

  if (str == "coffee") {
     write ("The waitress brings you a coffee.\n");
     say ("The waitress brings a mug of coffee to "+TPN+".\n");
     coffee = clone_object("/u/n/nightmask/private/coffee.c");
     coffee->move(this_object());
   return 1;
  }
  return 1;
 }
