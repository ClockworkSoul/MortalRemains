#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    set ("short", "Dining Hall");
    set( "long", @EndText
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/phalls1.c",
      "east" : MAIN+"/kitchen.c",
    ]) );

    set ("item_desc", ([
    ]) );
}

/* EOF */
