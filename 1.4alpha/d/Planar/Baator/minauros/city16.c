#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("long", @EndLong
You are standing within the massive black gates of the City of Minauros.
To the west is the fearsome Bottemless Bog, to the east is the Main Street
of Minauros. To the north and south gates lead into the gatehouses.
EndLong
    );
    set ("exits", ([   
    "north" : BAATOR+"minauros/city9.c",
    "south" : BAATOR+"minauros/city23.c",
    "east" : BAATOR+"minauros/city17.c",
    "west" : BAATOR+"minauros/city15.c"
    ]));
}


