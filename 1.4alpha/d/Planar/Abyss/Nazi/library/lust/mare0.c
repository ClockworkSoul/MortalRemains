/*
** File: mare0.c
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
The whine of the child grows louder too. You wonder if 
you should advance more...
EndText
    );
    set( "exits", ([
      "west" : LUST+"nightmare.c",
      "east" : LUST+"mare1.c",
    ]) );
    set( "item_desc", ([

    ]) );
    set("objects", ([
      "hellen" : NAZI_MON+"maid1.c",
    ]) );
    reset();

}



