#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    set ("short", "A Fancy Ballroom");
    set( "long", @EndText
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/phallcn.c",
      "west" : MAIN+"/phalln1.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
