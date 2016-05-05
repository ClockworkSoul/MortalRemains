#include "../cavern.h"

inherit ROOM_WITH_ROOTS;

void create()
{
    ::create();
    set( "short", "tunnel (n,s)" );
    set("base_long", @ENDTEXT
You are in a tunnel.
ENDTEXT
    );
    set( "exits", ([
        "north" : ROOMS "/tunnel1.c",
        "south" : ROOMS "/tunnel4.c"
    ]) );
    set("pre_exit_func", ([
        "south" : "roots_check"
    ]) );
    set( "item_desc", ([
        "tunnel" : "The narrow tunnel makes you very nervous.\n",
        "sounds" : "Low rumbling noises.\n"
    ]));
}
