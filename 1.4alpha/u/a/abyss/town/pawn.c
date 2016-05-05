#include <mudlib.h>

inherit SHOP ;

void create() {
    ::create();
    set ("light", 1) ;
    set("author", "cyanide");
    set ("long", wrap(
     "You find yourself in the freshly built pawn shop of Tantallon.  It looks \n"+
     "very nicely built and decorated.  You think you see some items behind a \n"+
     "counter.  The shop commands here are list, buy, sell, and appraise.\n",
      ) );
    set("short", "The Pawn Shop") ;
    set ("exits", ([
     "south"  :  "/u/a/abyss/town/t9.c",
    ]));
}
