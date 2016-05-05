#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set ("author", "cyanide");
    set ("short", "Cyanide's Vault of Fools");
    set( "long", @EndText
This is where Cyanide keeps the corpses of the foolish.
EndText
    );
    set( "exits", ([
      "portal" : MAIN+"/topiary.c",
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
