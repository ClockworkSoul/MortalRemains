#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("short", "Palace Hallway");
    set( "long", @EndText
This is where Cyanide keeps the corpses of the foolish.

There is a large, black, pulsating portal here.
EndText
    );
    set( "exits", ([
      "northwest" : MAIN+"/phalls1.c",
      "east" : MAIN+"/phalls3.c",
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
