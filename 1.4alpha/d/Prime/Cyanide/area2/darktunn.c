#include <mudlib.h>
#include "main.h"
inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set ("short", "Dark Tunnel");
    set( "long", @EndText
This is a dark tunnel with dim light to the northeast. The tunnel
is smooth but dusty and filled with twigs and leaves, debris
which becomes deeper as the tunnel branches into a wide corridor
leading southwest, and a narrower one leading southeast.
EndText
    );
    set( "exits", ([
      "northeast" : MAIN+"/ford.c",
      "southeast" : MAIN+"/ngarden.c",
      "southwest" : MAIN+"/nearstream.c",
    ]) );
    set ("item_desc", ([
      "debris" : "Mostly leaves and other dead plant material.\n",
      "tunnel" : "Just a tunnel. What's the matter? Afraid?\n",
      "twigs" : "They obviously don't belong here...\n",
      "leaves" : "Several varieties of garden plants and bushes.\n",
    ]) );
}
