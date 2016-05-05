#include "../cavern.h"

inherit ROOM_WITH_ROOTS;

void create()
{
    ::create();
    set( "short", "tunnel (e,w)" );
    set("base_long", @ENDTEXT
You are in a tunnel.
ENDTEXT
    );
    set( "exits", ([
        "east"  : ROOMS "/cave3.c",
        "west"  : ROOMS "/tunnel1.c",
    ]) );
    set("pre_exit_func", ([
        "east"  : "roots_check"
    ]) );
    set( "item_desc", ([
        "tunnel" : "The narrow tunnel makes you very nervous.\n",
        "sounds" : "Low rumbling noises.\n"
    ]));
}
