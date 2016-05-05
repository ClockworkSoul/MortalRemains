#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("safe", 1);
    set ("short", "A Hidden Sanctuary" );
    set( "long", @EndText
You have managed to enter a hidden sanctuary, where the forces of
darkness cannot find you.
   The walls of the sanctuary are made of pure gold, and seem to glow
with a holy radiance of their own. There is an ornate ivory altar
here, which pulses with the very fiber of goodness.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/nearstream.c",
    ]) );
}
