#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
	set( "short", "Seb's Bedroom" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
This is Seb's bedroom.  Unless you're stayin, bug off! This room is
for sleeping, and..um..stuff.  The bed is really comfy and kinda large
The stairs lead downstairs.

EndText
    );
    set( "exits", ([
"down" : "u/s/sebastian/livingroom.c",
    ]) );
set( "item_desc",([
	"bed" : "It's large and comfy, care to sleep?\n",
]) );
}
