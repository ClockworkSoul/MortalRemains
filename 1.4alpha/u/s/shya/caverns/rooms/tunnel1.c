#include "../cavern.h"

inherit ROOM_WITH_ROOTS;

void create()
{
    set( "short", "tunnel (s,e,w)" );
    set("base_long", "You are in a tunnel.\n"
"You can go further into the caverns by going south"
" towards darkness and the wierd sounds coming from below."
"  You can go west to leave this place or east to continue"
" into more darkness.");
    ::create();
    set( "exits", ([
        "east"  : ROOMS "/tunnel2.c",
        "west"  : ROOMS "/cave2.c",
        "south" : ROOMS "/tunnel3.c"
    ]) );
    set("pre_exit_func", ([
        "east"  : "roots_check",
        "south" : "roots_check"
    ]) );
    set( "item_desc", ([
        "tunnel" : "The narrow tunnel gets narrower and makes you very nervous.\n",
        "sounds" : "Low rumbling noises coming from the south.\n"
    ]));
}
