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
    "stairs" : KEEP+"keep10.c",
    "south" : KEEP+"keep7.c",
  ]) );
  set("item_desc" , ([
    "shadows" : "They dance happily along the walls from the candle light.\n",
  ]));
reset();
}
