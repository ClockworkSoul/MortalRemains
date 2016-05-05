
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
set("short","Entrance to Pepperland");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
After walking through the portal, you find yourself in a world
where most of the people are very flat. The look as if the life
has been sucked out of them as they have a grayish color
through out their body. Clearly, something is not right.
EndText
  );
set("smell","It smells rotten, like all of the life has been taken from it. \n");
set("listen","You can't hear a thing. There is no music at all.\n");
  set( "exits", ([
"portal":INS_ROOM+"cave10.c",
"west":INS_ROOM+"cave12.c",
  ]) );

set ("item_desc",([
"people":"These people look like they have only 2 dimensions to them!\n",
"fields":"These are strawberry fields that go on forever. \n",
]));
reset();
}

void reset(){
object bm1, bm2;

if(!present("blue meanie",this_object())){
bm1= clone_object (INS_MON+"bmean.c");
bm1 -> move(this_object());

bm2 = clone_object (INS_MON+"bmean.c");
bm2 -> move(this_object());

}
}
