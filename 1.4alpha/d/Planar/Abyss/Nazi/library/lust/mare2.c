/*
** File: /u/n/nsd/lust/mare2.c
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
set("author", "nsd");
    set( "short", "Your nightmare is...");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
...The flower path continues to the north. The scent of
jasmines grows stronger as you advance. You feel weird.
For moments, the whining seems to stop only to become
screams of fear...
EndText
    );
    set( "exits", ([
"south" : LUST+"mare1.c",
"north" : LUST+"mare3.c",
    ]) );
    set( "item_desc", ([

    ]) );
    set("objects", ([
"sasha" : NAZI_MON+"maid3.c",
    ]) );
    reset();

}



