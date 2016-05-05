
#include <mudlib.h>
#include <config.h>
#include <kyrie.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
set("author","spooner");
    set( "light", 1 );
set("short", "deeper into the Forest of Kyrie");

    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)

    set( "long", @EndText
You come to a end in the trail here.  You notice something that
seems very odd here,  you notice that the stream goes into a cave
and disappears into the hillside, also the shadows are no longer
anywhere to be found.  You feel a little more comfortable here.
EndText
    );

set("item_desc", ([
"stream" : "This stream looks very clean and cold.\n",
"hillside" :"you notice that the stream goes right into the hill here.\n",
]) );

    set( "exits", ([
"south" : KYRIE+"kyrie2.c",
"enter" : KYRIE+"kyrie4.c",
    ]) );
}
