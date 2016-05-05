#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("objects",(["monster" : "/u/v/valkyrie/bedmon.c"]) );
    reset();
    set( "light", 1 );
    set( "short", "Val's nubby-land" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or
    //spaces)
    set( "c_long", @EndText
The workroom is splashes of color mixed with lots of natural lighting. The
furniture is dark wood with brightly colored seats and pillows, all very
comfy for lounging about, and seem to have a warm fuzzy bumpy texture,
commmonly referred to as nubby. A few wooden tables are scattered about
holding mugs, books and gadgets. The light scent of incense wafts through
the room, with some music in the background setting the perfect mood for
the goofy engineer that resides here.
EndText
    );
    set( "exits", ([
      "insanity" : VOID,
    ]) );
}

void init() {
    ::init();
}
