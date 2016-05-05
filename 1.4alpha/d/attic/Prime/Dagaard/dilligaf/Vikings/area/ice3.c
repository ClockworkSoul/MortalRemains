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
  set("short" , "A path through the village");
  set( "long" , @EndText
  You have wandered into a Viking village. Shouts and commotion can be
  heard off far to the west. While right beside the road there is a small
  house. From inside the house you can hear singing and shouting. The 
  sleet is still pummeling down on you, but you don't take any notice,
  you are too interested as to what is going on elsewhere.

EndText
  );
  set( "exits", ([
     "west" : ICE+"house1.c",
     "south" : ICE+"ice5.c",
     "north" : ICE+"ice2.c",
  ]) );
  set("item_desc" , ([
    "house" : "It seems rather warm inside, though you are sure that you can hear shouting coming from within.\n",
    "road" : "A small path running through the center of the village. There doens't seem to be any street signs, but you aren't surprised.\n",
  ]));
  create_door("west","east","A strong oaken door","closed","");
reset();
}
