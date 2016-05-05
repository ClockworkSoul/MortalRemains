/*
** File: mare7.c
** Author: Lady Nsd
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
jasmines ceased. You hear a mocking male laughter, 
followed by desperate screams of a child. You see a
strange dark chamber to the north. Seems to be the 
place where those screams come from...
EndText
    );
    set( "exits", ([
      "west" : LUST+"mare6.c",
      "north" : LUST+"mare8.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "lord edrich" : NAZI_MON+"edrich.c",
    ]) );
    set("pre_exit_func", ([
      "north" : "hehere"
    ]) );
    reset();
}

int hehere() {
    if(present("edrich", TO)) {
	write("Lord Edrich won't let you go north.\n");
	return 1;
    } else {
	return 0;
    }
}

/* EOF */
