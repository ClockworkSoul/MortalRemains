#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndText
You find yourself on a long dusty road made of uneven black 
cobblestones. To the east, closer now, is the Iron Citadel.
EndText
    );
    set ("short","A Long Road");
    set ("exits", ([
      "west" : BAATOR+"avernus/plain8.c",
      "east" : BAATOR+"avernus/fortbel7.c"
    ]));
}
