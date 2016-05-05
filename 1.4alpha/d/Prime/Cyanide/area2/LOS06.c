#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are near the southern end of a land of shadow. The ground here is
soft and spongy, and it becomes quicksand to the south. North and east of
here are gentle rolling hills. A gentle sea breeze wafts over a steeply
sloping path to the west.
EndText
    );
    set( "exits", ([
      "northeast" : MAIN+"/LOS03.c",
      "east" : MAIN+"/LOS04.c",
      "southeast" : MAIN+"/LOS05.c",
      "west" : MAIN+"/ocean.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
    ]) );
}
