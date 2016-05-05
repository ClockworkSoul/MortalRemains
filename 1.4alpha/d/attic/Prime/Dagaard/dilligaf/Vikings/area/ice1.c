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
  set("short" , "Just outside a village");
  set( "long" , @EndText
  You stand at the Entrace of what looks to be a village. The frozen
  tundra behind you tells you that these are a hard people. As you turn
  to look behind you, you can hear the howling of wolves and the sleet
  pummeling your eyes makes you with you were inside by a fire somplace.

EndText
  );
  set( "exits", ([
    "south" : ICE+"ice2.c",
  ]) );
  set("item_desc" , ([
    "tundra" : "You look behind you and wonder where the path went to.\n",
    "path" : "The path as almost all but totally dissapeared.\n",
    "sleet" : "You look right at the sleet and immediately wish you hadn't, it stings your eyes and makes them water.\n",
    "fence" : "It looks as if it was made with an entire forrest.\n",
  ]));
  create_door("south" , "north" , "A large blackened door. Attached to a very large fence which looks as if it has been made with an entire forrest.","closed","");
reset();
}
