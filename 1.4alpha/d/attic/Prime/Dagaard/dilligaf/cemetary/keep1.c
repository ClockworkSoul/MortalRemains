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
  set("short" , "Just inside the gate");
  set( "long" , @EndText
  You have somehow managed to bypass the gate. You now stand in the
  massive courtyard of a giant keep. It looms up above you and you
  cannot see the top. There is no other life around you, it seems as
  if everything is dead...there is no sound and you wonder if you really
  want to go in here.

EndText
  );
  set( "exits", ([
    "out" : CEMETARY+"cem4.c",
    "south" : KEEP+"keep2.c",
  ]) );
  set("item_desc" , ([
    "gate" : "You have made it through the gate...now what?\n",
    "courtyard" : "A large courtyard, all the grass seems to have been burned.\n",
    "grass" : "Its seems to have been burned, what possibly could have done all this?\n",
    "keep" : "A massive keep.\n",
  ]));
  create_door("south" , "north" , "A large black door","locked","keep_key");
reset();
}
