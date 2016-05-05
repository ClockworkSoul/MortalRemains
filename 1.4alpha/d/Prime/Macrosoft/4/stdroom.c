// The collective

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A steel catwalk");
    set("long", @EndText
You have walked out onto a steel catwalk, suspended hundreds of feet above
the ground. Along the sides of the catwalk, and along every wall, are 
hundreds of humanoids, all standing motionless in individual alcoves.
EndText
    );
    set("item_desc", ([
      "humanoids" : "They all seem to be cybernetically enhanced.\n",
      "catwalk" : "It is very plain.\n",
      "alcoves" : "They seem to be feeding the humanoids some kind of energy.\n",
    ]) );
    set("objects", ([
      "borg" : MS_MON("borg.c")
    ]) );
reset();
}



/* EOF */              
