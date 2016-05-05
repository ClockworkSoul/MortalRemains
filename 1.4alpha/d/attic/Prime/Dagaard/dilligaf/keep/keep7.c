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
  set("short" , "Lord Soth's Keep. [2nd Floor]");
  set( "long" , @EndText
  You walk down the hallway and the candles give off an eerie light. 
  Shadows dance along the walls, and you almost think that they might
  be alive, you start to get shivers up your spine.

EndText
  );
  set( "exits", ([
    "north" : KEEP+"keep8.c",
    "south" : KEEP+"keep6.c",
    "east" : KEEP+"keep9.c",
  ]) );
  set("item_desc" , ([
    "shadows" : "They dance happily along the walls from the candle light.\n",
    "door" : "You can barely make out the door on the east wall.\n",
  ]));
  create_door("east" , "west" , "You can barely make out this door...the only give away is the aura radiating from it." , "locked" , "skeleton_key");
reset();
}
