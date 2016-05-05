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
set("short","Northern Caves");
  set( "long", @EndText
This cave slopes upward from the main room. The floor of the cave
feels very slick and there is a lot of clutter on the floor. 
EndText
  );
  set("smell", "It smells like a fresh day in the country, with a touch of \n"
               "chalk dust floating in the air.\n");
set("forbidden", 1);
  set("listen", "You can hear the sounds of a calliope farther down the passage.\n");
set("exits",([
"south":INS_ROOM+"cave1.c",
"north": INS_ROOM+"cave3.c",
]));


}


void reset()
{
  seteuid( getuid() );
  ::reset();
if(!present("dsword",this_object())){
object dsword;

dsword= clone_object(INS_MON+ "dsword.c");
if (dsword)
dsword-> move (TO);

  }
}
