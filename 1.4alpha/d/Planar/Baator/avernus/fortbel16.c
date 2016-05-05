#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("long", @EndText
You have entered the vast dungeons of the the Warlord Bel. The iron walls
here are bloodstained and pitted with age, and the screams of the 
occupants echo through the mazelike tunnels, setting your nerves on edge.
The very air itself is charged with fear.
EndText
    );
    set ("short", "The Dungeons of the Iron City");
    set ("exits", ([
        "up" : BAATOR+"avernus/fortbel8.c",
        "north" : BAATOR+"avernus/fortbel17.c",
        "east" : BAATOR+"avernus/fortbel18.c",
        "south" : BAATOR+"avernus/fortbel19.c"
    ]));
}
