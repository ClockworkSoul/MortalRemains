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
  set("short" , "Just inside the main gate");
  set( "long" , @EndText
  You stand just inside the massive fence. On the other side you can hear
  the dissapointed wailings of the wolves. The sleet is still barreling
  down on you, but its really not as strong. You relax a little, over
  to the east you can see some figures around a glowing campfire, and
  from the west you can smell some of the most delicious smells you
  can imagine.

EndText
  );
  set( "exits", ([
    "north" : ICE+"ice1.c",
    "south" : ICE+"ice3.c",
    "east" : ICE+"ice4.c",
  ]) );
  set("smell" , ([
    "food" : "You lift you nose and waft in the wonderful aroman.\n",
  ]) );
  set("listen" , ([
    "wolves" : "You can hear the pathetic howling of the wolves outside.\n",
    "howling" : "Wolves on the other side of the fence...hopefully.\n",
  ]) );
  set("item_desc" , ([
    "figures" : "You can't make them out too well from here, but you suppose that they are the guards.\n",
    "fence" : "Luckily it is here, or else you would be out in the freezing weather.\n",
    "campfire" : "You wonder if you shouldn't get warm.\n",
  ]));
  create_door("north" , "south" , "A large black door holding back the elements","closed","");
reset();
}
