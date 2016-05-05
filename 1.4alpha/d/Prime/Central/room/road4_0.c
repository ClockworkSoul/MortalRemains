// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", RD_X);
    set("long", wrap(
	"You stand at the edge of "+CITY_NAME+". "+
	"To the south is Fort Blood, one of the largest and "+
	"best equipped military installations in the region. It "+
	"is known that you could enter there and enlist, if you "+
	"so chose. To the north, however, is the "+CITY_NAME+
	" Community College, where people commonly go to pick up "
	"a few extra skills, advance their career, or even change "+
	"careers entirely."
      ) );
    set("exits", ([
      "north" : COLLEGE("campus"),
      "west" : M_ROOM+"road3_0.c",
"east" : M_ROOM+"road5_0.c",
    ]) );
    set("item_desc", ([
    ]) );
}

// EOF
