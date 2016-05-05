inherit ROOM;
#include "sophia.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
set( "short", "Halfway to hell stop" );
set( "long", wrap(
"A plain wooden plank platform in the middle of nowhere. Several people "+
"stand here including a large man who doesn't look like he could walk "+
"10 feet but you see no transport of any kind that could have "+
"brought him here. "
) );
    set( "exits", ([
"train" : "/u/s/sophia/pad4.c",
    ]) );
    set("item_desc", ([
"man" : "A huge man in a purple velvet waistcoat. His snakeskin boots 
tap impatiently on the wooden planks and he looks the type to 
be pacing except that he avoids the only available area left on the
platform to pace.\n",
"platform" : "A plain wooden platform made of planks weathered
a light gray by the sun in most places.\n",
    ]) );
}
void init() {
add_action("lift", "lift");
}
int lift(string str) {
if(str=="ring") {
write("A door opens, you find stairs, lose your footing, and fall.\n");
say(TPN+" simply disappears.\n");
TP->move_player(SOPHIA+"pad6.c");
say(TPN+" drops in from somewhere above. \n");
return 1;
}
}
