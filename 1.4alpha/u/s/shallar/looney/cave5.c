#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
set("light", 0);
  set("author","shallar");
set("short","Top Cavern");
  set( "long", @EndText
This is the home of the Purple People Eater of lore. There are bones
all over the floor of people who didn't not have the good sense to 
get the heck out of here before the monster found them. And it looks
like it is lunch time....
EndText
  );
set("exits",([
"down":INS_ROOM+"cave4.c",
]));


}


void reset()
{
  seteuid( getuid() );
  ::reset();
if(!present("ppeater",this_object())){
object ppeater;

ppeater= clone_object(INS_MON+"ppeater.c");
if (ppeater)
ppeater-> move (TO);
}
}
object helion;
