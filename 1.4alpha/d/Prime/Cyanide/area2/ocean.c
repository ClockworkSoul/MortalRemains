#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "blue" : 3,
  "black" : 2,
  ]) );
  set ("short", "The Great Underground Ocean");
  set( "long", @EndText
You are at the shore of an amazing underground sea, the topic of many a
legend among adventurers. Few were known to arrive at this spot,
and fewer to return. There is a heavy surf and a breeze is blowing
on-shore. The land rises steeply to the east, and quicksand prevents
movement to the south. A thick mist covers the ocean and extends over the
hills to the east. A path runs north along the beach.
EndText
  );
  set( "exits", ([
"north" : MAIN+"/clbase.c",
"northeast" : MAIN+"/LOS08.c",
"east" : MAIN+"/LOS07.c",
"southeast" : MAIN+"/LOS06.c",
  ]) );

set ("item_desc", ([
"shore" : "A great beach of glistening black sand.\n",
"sea" : "The surf is pounding. It may be a bad idea to swim here.\n",
"water" : "The sea is rough and the surf pounds.\n",
"surf" : "It look deadly. Only a fool would attempt to swim here.\n",
"land" : "It appears that it leads to some kind of barren wasteland...\n",
"mist" : "It covers the ocean, making it invisable at any distance.\n",
]) );
}

void init () {
add_action ("swim_func", "dive");
add_action ("swim_func", "swim");
add_action ("exits","exits");
}

int exits() {
write ("You begin to get a nasty headache.\n");
say (NAME+" begins to look very confused.\n");
return 1;
}

int swim_func() {
  write ("With confidence, you dive into the surf.\n"+
         "You feel an immense weight upon you, and everything turns dark...\n"+
         "You take a deep breath, and get only water...\n\n"+
         "You fool.\n\n");
  say(NAME+" dives into the dark waters and dissapears under the pounding surf.\n");
  this_player()->move(MAIN+"/vault.c");
  this_player()->set("hit_points", -1);
return 1;
  }
