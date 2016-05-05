#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("author","shallar");
set("short","main entrance");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
This is the main hall in the cave. You see strange, inhuman figures
darting about from place to place. It looks like anything can go here
and there is something for all adventurers to see. The noise echoes
off of the stone walls.
EndText
  );
set("listen","There is a lot of laughter and screaming echoing in here.\n");
  set( "exits", ([
"out":INS_ROOM+"path3.c",
"north":INS_ROOM+"cave2.c",
"south":INS_ROOM+"cave6.c",
"east":INS_ROOM+"cave10.c",
"west":INS_ROOM+"cave14.c",
"down":INS_ROOM+"cave18.c",
  ]) );

set("pre_exit_func", ([
"down":"block",
]));
set ("item_desc",([
"figures":"Any type of strange creature can be found here. It almost \n" +
"looks like something out of a Jungian experiement. Somehow, this cave \n" +
"has tapped into people's dreams, and this came out. \n",
"echo":"The echos vibrate in your ears.\n",
]));
}

int block() {
write("You try to go down, but a small child, his sister, and a third \n" +
"child with a red hat poke their heads out of the hole. \n" +
"The child looks at you and sez: I'm sorry, but the wheel of morality \n" +
"is currently on the fritz. The last time we spun it, all we received \n" +
"was campaign literature for Pat Buchanan. There may be just a tiny \n"
"problem with it. \n"
+"At that point, a pair of small white mice emerge from the hole asking \n" +
"each other what they are going to do tonight... \n");
return 1;
}
void reset() {

object broom;

if(!present("broom",this_object())){
broom= clone_object (INS_MON+"broom.c");
broom-> move(this_object());
}
}
