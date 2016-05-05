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
  set("objects" , ([ "lord soth" : MON+"lordsoth.c" ]) );
  set( "light", 1 );
  set("short" , "Lord Soth's Office. [4th Floor]");
  set( "long" , @EndText
  You have managed to make it into Lord Soth's personal 'office'. A
  large picture lays before you, hoisted up above the fireplace. It
  resmebles the one you saw earlier downstairs. It is a very non-descript
  office, nothing of any real value.

EndText
  );
  set( "exits", ([
    "south" : KEEP+"keep11a.c",
  ]) );
  set("item_desc" , ([
    "picture" : "It looks as if to be his family, or what once was his family.\n",
    "fireplace" : "Strange. The fireplace emits no warmth even though there is a raging inferno inside it.\n",

  ]));
  create_door("south" , "north" , "A large set of double doors" , "locked" , "soth_key");
reset();
}
