/*
** File: /u/n/nsd/library/sauna/massage.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"

inherit ROOM;



void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Massage room");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
Welcome to the massage room. Here you can relax all
of your muscles and tensions. You'll feel brand new
after this experience. There's a sign in the wall.
EndText
    );
    set( "exits", ([
"west" : SAUNA+"sauna1.c",
"south" : "?",
    ]) );

    set( "item_desc", ([
    ]) );
}

/* EOF */
