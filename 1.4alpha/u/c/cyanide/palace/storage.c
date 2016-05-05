#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    set ("short", "Old Storage Room");
    set( "long", @EndText
EndText
    );
    set("exits", ([
      "north" : MAIN+"/kitchen.c",
    ]) );
}
