#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short", "The Lair of the Queen of Dragonkind");
    set ("long", @EndText
You are in a massive cave complex illuminated by torches fixed to the 
cavern walls. Strangely there are no dragons in here, and the acrid smell
is much less potent.
EndText
    );
    set ("exits", ([
      "east" : BAATOR+"avernus/lair5.c"
    ]));
}
/* EOF */
