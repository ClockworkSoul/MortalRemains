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
  set("objects" , ([ "wraith" : MON+"wraith2.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "Lord Soth's Keep. [2nd Floor]");
  set( "long" , @EndText
  You have entered a lair of some sort, the walls are thick with cobwebs
  and the blackness of the bricks make you think that the creature that
  lives here, just doesn't like light at all. The rest of the room
  really has nothing of interest.

EndText
  );
  set( "exits", ([
    "west" : KEEP+"keep7.c",
  ]) );
  set("item_desc" , ([
    "cobwebs" : "Thick cobwebs, hope you like spiders.\n",
    "bricks" : "Large blackened bricks, almost soot covered.\n",
  ]));
  create_door("west","east","A large oak door with a magical aura surrounding it.","locked","skeleton_key");
}
