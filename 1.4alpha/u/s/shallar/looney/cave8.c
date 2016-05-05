
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
set("short","outside the gazebo");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
This is a path near a popular gazebo in this park. The music
conitnue on in the background and sounds like ragtime. Your
muscles relax in this setting. There is a restaurant in the gazebo
where you can rest your tired legs.
EndText
  );
set("smell","It smells like a fresh day in the country, with a touch of \n"+
"chalk dust floating in the air.\n");
set("listen","You can hear the sounds of a calliope farther down thepassage.\n");
  set( "exits", ([
"north":INS_ROOM+"cave7.c",
"southeast":INS_ROOM+"cave9.c",
  ]) );

set("item_desc",([
"restaurant":"A place to the southeast where you can take a break. \n",
"gazebo":"A wodden structure for lovers to sit under and enjoy the nice scenery. \n",
]));
set("objects",([
"penguin":INS_MON+"peng2.c",
]));
reset();
}
