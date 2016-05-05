// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set( "light", 1 );
    set("short", MUD_NAME+" Bug Room");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
This is the bug room, which I'm sure we'll be using ALOT.
Post away, and we'll work as fast as we can.  ;)
EndText
    );
    set( "exits", ([
      "north" : "/d/Ancients/rooms/wizrm.c",
    ]) );
    call_other("/d/Ancients/obj/bugboard","dummy");
}

void init() {
}
