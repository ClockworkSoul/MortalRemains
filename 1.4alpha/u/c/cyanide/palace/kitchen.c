#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
    seteuid(getuid());
    set ("short", "Ruined Kitchen");
    set( "long", @EndText
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/dininghall.c",
      "east" : MAIN+"/phallcs.c",
      "south" : MAIN+"/storage.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
void init () {
    add_action ("exits","exits");
}
int exits() {
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}
