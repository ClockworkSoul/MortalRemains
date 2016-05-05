#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Abbey Road");
    set( "long", @EndText
You are walking along a small cobblestone path leading up to what
looks like an old Abbey. The walkway starts to look a bit warn the
further you go east. The cobblestone walk leads back west, and
continues to the east. The walls of the town are to the north of
you, while south just seems to be the backs of buildings.
EndText
    );
    set( "exits", ([
     "east" : RM+"AR3.c",
     "west" : RM+"AR1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "buildings" : "Just the backs, more like an ally.\n",
     "walls" : "Weatherbeaten and cracked, they house the town.\n",
     "cracks" : "Nothing special, just cracks.\n",
     "walk" : "It looks sort of worn, it's made of cobblestones.\n",
     "cobblestones" : "They make up the path, worn from years of use.\n",
     "abbey" : "It's looks very old and to the east of you.\n",
    ]) );
}
