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
The path continues on. You get closer to Barrelhaven as you go
north and that noise to the west grows progressively louder with
each step.
EndText
  );
set("listen","Whispy sounds of laughter and screaming from the west.\n");
  set( "exits", ([
"south":"/u/s/shallar/boneville/road2.c",
"north":"/u/s/shallar/looney/path1.c",
  ]) );

set("item_desc",([
"noise":"It's noise... you listen to it... got it?\n",
"road":"It's the same dirt road you've been on for a while now.\n",
]));
}
