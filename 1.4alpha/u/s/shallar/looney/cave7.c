
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
set("short","route to fairgrounds");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
As you walk, the area becomes much brighter than the caves. The colors
grow more vibrant & it almost feels like a Utpoia. All of the madness is gone
and you are at peace. Don't mess it up!
EndText
  );
set("smell","It smells like a fresh day in the country, with a touch of \n"+
"chalk dust floating in the air.\n");
set("listen","You can hear the sounds of a calliope farther down the passage.\n");
  set( "exits", ([
"north":INS_ROOM+"cave6.c",
"south":INS_ROOM+"cave8.c",
  ]) );

set("item_desc", ([
"colors":"Bright primary colors decorate this landscape. Some of them start to rub off on you. \n",
"peace":"Something a hardened adventurer like you never thought you would find. \n",
]));
reset();
}

void reset(){
object h1, h2, h3;

if(!present("horse",this_object())) {
h1= clone_object (INS_MON+"merry1.c");
h1-> move(this_object());

h2= clone_object (INS_MON+"merry2.c");
h2-> move(this_object());

h3= clone_object (INS_MON+"merry3.c");
h3-> move(this_object());
}
}
