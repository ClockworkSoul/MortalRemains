#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are at the eastern end of a dark, featureless landscape of shallow
hills. Paths to the east and southeast re-enter the rock.
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/creepy.c",
      "southeast" : MAIN+"/foggy.c",
      "south" : MAIN+"/LOS05.c",
      "southwest" : MAIN+"/LOS04.c",
      "west" : MAIN+"/LOS03.c",
      "northwest" : MAIN+"/LOS02.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
    ]) );
}
