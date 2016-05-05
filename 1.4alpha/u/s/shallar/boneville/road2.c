#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("author","shallar");
set ("short", "a dirt road");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
This road goes north to Barrelhaven and south to town, but you
start to hear some fiant noise from the west. It almost sounds
like laughter, but that might be the wind.
EndText
  );
  set( "exits", ([
"south" : "/u/s/shallar/boneville/road1.c",
"north" : "/u/s/shallar/boneville/road3.c",
  ]) );

set ("item_desc", ([
"wind":"You can't see the wind... don't you know anything?\n",
"road":"A generic dirt road going north to south. Any questions?\n",
]));
}
