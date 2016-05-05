
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
This is the Throne of a Huge Bear.  You notice that the 
Bear is licking his chops at the sight of you.  You really 
feel uncomfortable here.  There are some torches onthe 
walls.  There is also a huge pile of bones and carcasses.
EndText
    );

set("item_desc", ([
"torches" : "there are many torches here to keep the throne very well lite.\n",
"bones" : "As you look at the bones you notice the remain of some of your friends.\n",
]) );

    set( "exits", ([
"south" : KYRIE+"kyrie4.c",
    ]) );
}
