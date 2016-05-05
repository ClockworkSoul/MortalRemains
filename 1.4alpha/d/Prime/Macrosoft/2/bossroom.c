// Cyanide coded this.

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "The Boss's Office");
    set("long", wrap(
	"You are in a smallish sized office with ghastly "+
	"green carpets. A huge desk takes up most of the space "+
	"in here, and the rest seems to be taken up by various "+
	"plastic plants."
      ) );
    set("exits", ([ 
      "west" : FLOOR_2("floor10.c"),
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([ "barbara" : MS_MON("2boss.c") ]) );
reset();
}

/* EOF */
