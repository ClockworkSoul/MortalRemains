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
This is a wide dirt road that wanders to the north. You have heard 
rumors of a great conflict going on in the town of Barrelhaven.
EndText
  );
  set( "exits", ([
"north" :"/u/s/shallar/boneville/road2.c",
  ]) );

set( "item_desc",([
"road":"It's a dirt road for crying out loud. Look up before you run into something!\n",
]));
}
