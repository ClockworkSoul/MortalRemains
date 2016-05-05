#include <mudlib.h>
#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    set ("short", "Preparation Room");
    set( "long", @EndText
This is where Cyanide appears before visiting dignitaries. He meets
them with his advisors and any servants that are deemed important
enough for the task at hand.
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/room8'5.c",
      "east" : MAIN+"/gpathw.c",
    ]) );
    set ("item_desc", ([
    ]) );
}

/* EOF */
