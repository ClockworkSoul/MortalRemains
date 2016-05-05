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
  set("objects" , ([ "dragon" : MON+"blackdragon.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "Lord Soth's Keep. [4th Floor]");
  set( "long" , @EndText
  This is a HUGE cavern, baring a very close similarity to the one that
  you saw a few floors below. Catherdral like pillars support the vast
  ceiling, candles light up the room and glint off the gold that seems
  to be encrusted in the walls. Simply a magnificent room.

EndText
  );
  set( "exits", ([
    "north" : KEEP+"keep12.c",
    "down" : KEEP+"keep10.c",
  ]) );
  set("item_desc" , ([
    "gold" : "Nuggets and coins, encrusted in the walls...though impossible to get out...they are magnificent to behold.\n",
    "ceiling" : "Its way up there, 50-60 feet.\n",
  ]));
  create_door("north" , "south" , "A large set of double doors, you can only wonder whats on the other side" , "locked" , "soth_key");
}
