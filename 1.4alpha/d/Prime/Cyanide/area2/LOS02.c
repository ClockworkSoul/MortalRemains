#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    seteuid ( getuid() );
    set("author", "cyanide");
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are in a shadowy land of low rolling hills stretching out to the west
and south. The land is bordered to the north by a massive stone wall.
Ancient and weathered, the wall has crumbled enough at one point to
permit passage.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/barren.c",
      "east" : MAIN+"/LOS01.c",
      "southwest" : MAIN+"/LOS07.c",
      "west" : MAIN+"/LOS08.c",
      "south" : MAIN+"/LOS03.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
