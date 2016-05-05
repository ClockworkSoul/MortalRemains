
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"
object wraith;

void reset (status arg) {
  ::reset(arg);
  if(!arg) {
    set_short("A small hidden alcove");
    set_long (
" You have come accross a small alcove set off from the main passage.\n"+
" It appears that one could wait hidden here and ambush any traffic that\n"+
" comes along. It is a wonder that you weren't taken by surprise.\n");
    set_items(({
        "alcove#small alcove","Just look around, it isnt very big.",
        "passage#main passage","The passage is to the south.",
        "traffic","You are the only traffic passing though that you can see.",
    }));
set_exits(({
        PATH+"room10.c","south",
    }));
  }
  if(!wraith){
    wraith = clone_object(PATH+"mobs/wraith.c");
    move_object(wraith, this_object());
  }
}
