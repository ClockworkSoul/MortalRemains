#include "main.h"

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();//<- gets all the information from the original create()
    seteuid( getuid());
    set( "light", 1 );
    set ("short", "Lim-Dul's Arch");
    set( "long", @EndText
Two huge arches, over fifty feet in height, span the main road of
Urborg, greeting those who pass through the city gates. A huge
dragon head decorates each keystone, made of the same glassy black
stone used to construct the arches.
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/room2'5.c",
      "east" : MAIN+"/room4'5.c",
      "phase" : MAIN+"/room2'5.c",
    ]) );
    set ("exit_suppress", ({ "phase" }) );
    set ("exit_msg", ([
      "phase" : "$N passes through the great iron gates.\n",
    ]) );
    create_door ("west", "east", "Great black iron doors", "locked", "sooty_key");
}
void init () {
    add_action ("exits","exits");
}
int exits() {
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}
