#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndText
You come to stand before a massive cavern leading into the heart of a 
great mountain. You tremble with a profound sense of inferiority as you 
gaze upon the sheer magnitude of the cave entrance: it seems to be at least
one hundred feet in height, and three times a wide. The reptilian 
footprints in and around the cave are large enough to swim in.
EndText
    );
    set ("short","Before a Great Cavern");
    set ("exits", ([
      "east" : BAATOR+"avernus/ave5.c",
      "west" : BAATOR+"avernus/lair6.c"
    ]));
    set("objects", ([
      "paragonred" : BAATOR+"monsters/paragonred",
    ]) );
    reset();
}

int go(string str) {

      if (!str || str != "west") return 0 ;
      if (present("dragon", TO )) {
       if (wizardp(TP)) {
	 write("The dragon steps out of your way and bows grandly.\n") ;
	  say("The dragon steps out of "+TPN+"'s way and bows grandly.\n") ;
       return 0 ;
      }
    if (TP->query_level()<20) {
      write("The huge red dragon laughs heartily at you.\n") ;
       say("The huge red dragon laughs heartily at "+TPN+".\n") ;
	return 1;
     } else {
     write("The huge red dragon stares at you calmly as you walk past.\n") ;
   say(wrap("The huge red dragon stares at "+TPN+" calmly as "+
    objective(TP->query("gender")) + 
      " walks past.")) ;
  return 0 ;
      }
   return 0 ;
   }
}

void init() {
    add_action("go", "go") ;
}
