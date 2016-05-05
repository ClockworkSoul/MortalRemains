
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
set("short","Pepperland");
  // NB: "@EndText" should not have spaces after it.
  set( "long", @EndText
You continue to wander the fields of Pepperland, trying to stop the
Blue Meanies. You still see a lot of people who have been turned into
statues by the villainous invaders.
EndText
  );
set("smell","It smells rotten, like all of the life has been taken from it. \n");
set("listen","You can't hear a thing. There is no music at all.\n");
  set( "exits", ([
"east":INS_ROOM+"cave11.c",
"west":INS_ROOM+"cave13.c",
  ]) );

set ("item_desc",([
"fields":"These normally lush, strawberry fields have turned gray.\n",
"people":"Citizens of Pepperland who were turned into statues by the \n"+
"weapons of the Blue Meanies.\n",
"statues":"People frozen in time by the invaders.\n",
]));
reset();
}

void reset(){
object hd, app;

if(!present("hand",this_object())){
hd= clone_object (INS_MON+"hand.c");
hd-> move(this_object());
}

if(!present("apple",this_object())){
app= clone_object(INS_MON+"apple.c");
app -> move (this_object());

}
}
