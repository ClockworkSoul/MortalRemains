#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You have entered a medium sized cave.
There is nothing in here.
EndText
    );
    set("short", "Inside a cave");
    set ("exits", ([
    "west" : BAATOR+"minauros/bog3.c"
    ]));
    reset();
}
