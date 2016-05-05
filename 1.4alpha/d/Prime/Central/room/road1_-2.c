// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", "A Narrow Alleyway");
    set("long", @EndText
This is a dark, narrow alleyway sandwiched between between an abandomed 
apartment building and a defunct book store. At the far end of the alley,
through a rended chain link fence, appears to be a machine embedded in the
wall, looking to you much like an ATM. You would have to continue east to
really get a good look at it.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"road0_-2.c",
      "east" : M_ROOM+"gangroom.c",
    ]) );
    set("smell", "It smells like a public toilet in the summertime, "+
      "only worse.\n");
    set("item_desc", ([
      "refuse" : wrap("Most of it is unidentifiable. Of course, "+
	"you probably don't want to know anyway."),
      "alley" : "You're in it.\n",
      "alleyway" : "You're in it.\n",
      "book store" : "The sign on it reads \"B rders  ooks\".\n",
      "atm" : "You can't see it from here.\n",
      "ATM" : "You can't see it from here.\n",
      "fence" : "It appears somebody had taken wire clippers to it.\n",
      "wall" : "Just walls. Pretty boring.\n",
    ]) );
}

// EOF                                                    
