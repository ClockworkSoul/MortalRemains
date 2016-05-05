/*
** File: nightmare.c
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
...A scent of jasmines that invades your nostrills.
This place is vaguely familiar, but you can't recall
why. Perhaps it has something to do with sitting on
the sofa. You hear the incessant cry of a child. It
annoys and scares you... 
All along the path you see beds of flowers.
A weather beaten sign stands here.
EndText
    );
    set( "exits", ([
      "east" : LUST+"mare0.c",
    ]) );
    set( "item_desc", ([
"sign" : "A weather beaten sign. You can read it.\n",
    ]) );

    set("objects", ([
    ]) );
    reset();
}

void init() {
    add_action("read_sign", "read");
}

int read_sign(string str) {
    if (!str || str!="sign") {
	write("Read what?\n");
	return 1;
    }

    say(TPN+" reads the sign.\n");
    write(@EndText
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
|                                                 |
|                                                 |
|               LUSTFUL NIGHTMARE                 |
|                                                 |
|     Make sure you get every item from all of    |
|     your kills before burying or eating them.   |
|     They may be useful at the end...            |
|     Don't miss any detail, or you won't be      |
|     able to wake.                               |
|     This might be the only friendly warning     |
|     you find here...                            |
|                                                 |
|                                                 |
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
    | |                                      | |
    | |                                      | |
    | |                                      | |
    | |                                      | |
    | |                                      | |
  VvVvVvV         @VvV@VvV@VvV@             VvVvVvV
EndText);
    return 1;
}
