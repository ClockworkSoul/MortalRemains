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
set("exits",([
"south":INS_ROOM+"cave2.c",
"up":INS_ROOM+"cave4.c",
]));


}


void reset()
{
  seteuid( getuid() );
  ::reset();
if(!present("helion",this_object())){
object helion;

helion= clone_object(INS_MON+ "helion.c");
if (helion)
helion-> move (TO);
  }
}
