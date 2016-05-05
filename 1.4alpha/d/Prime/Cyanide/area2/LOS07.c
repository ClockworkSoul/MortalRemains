#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are in a land of dark shadows and shallow hills, which stretch out in
all directions. To the west, the land dips sharply.
EndText
    );
    set( "exits", ([
      "northeast" : MAIN+"/LOS02.c",
      "southeast" : MAIN+"/LOS04.c",
      "west" : MAIN+"/ocean.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
    ]) );
}
