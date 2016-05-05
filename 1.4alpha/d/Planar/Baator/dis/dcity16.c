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
and strange, twisted daemons scurry in and out of them. In the distance,
the road appears to terminate at the base of a tall, twisted green
copper tower.
EndLong
    );
    set ("short","The Great Red Road");
    set ("exits", ([
        "north" : BAATOR+"dis/dcity11.c",
        "south" : BAATOR+"dis/dcity21.c",
        "east" : BAATOR+"dis/dcity17.c",
        "west" : BAATOR+"dis/dcity15.c"
    ]));
    reset();
}
