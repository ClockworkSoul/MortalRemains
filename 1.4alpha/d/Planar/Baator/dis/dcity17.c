#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
You are walking on a mile-long plush red carpet, the heat of which is
starting to burn the bottoms of your feet as you walk. Strange buildings
of slight rusted iron and dreen oxidized copper line the carpeted road,
and strange, twisted daemons scurry in and out of them. A few hundred
yards to the east, the road appears to terminate at the base of a tall,
twisted green copper tower.
EndLong
    );
    set ("short","The Great Red Road");
    set ("exits", ([    
        "north" : BAATOR+"dis/dcity12.c",
        "south" : BAATOR+"dis/dcity22.c",
        "east" : BAATOR+"dis/dcity18.c",
        "west" : BAATOR+"dis/dcity16.c"
    ]));
    reset();
}
