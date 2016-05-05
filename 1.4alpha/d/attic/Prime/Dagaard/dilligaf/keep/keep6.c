#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "Top of the stairs. [2nd Floor]");
  set( "long" , @EndText
  You stand at the top of the stairs going up and down from the first
  floor. The hallway extends before you, and FAR to the other end
  you can make out another set of stairs. There is a door on the east
  wall of the hallway, but you cannot see any windows.

EndText
  );
  set( "exits", ([
    "stairs" : KEEP+"keep3.c",
    "north" : KEEP+"keep7.c",
  ]) );
  set("item_desc" , ([
    "hallway" : "It extends before you for about 100 yards.\n",
    "door" : "Its a little bit more to the north, there is a slight aura coming from it.\n",
    "stairs" : "They are WAY down there.\n",
    "aura" : "Radiating from down the hallway, coming from one of the doors...maybe a ward of some kind.\n",
  ]));
reset();
}
