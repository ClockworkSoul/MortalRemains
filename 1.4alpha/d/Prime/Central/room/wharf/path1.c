inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "On A Small Path");
    set("long", @EndText
You seem to have stumbled onto a little used path overgrown with tall 
hardy shrubs, thick thorny vines, and poison ivy. Over time, a thick layer
of paper refuse has gotten blown into the tangled mass of growth, leaving
a layer of weathered coffee cups and decomposing newspapers. Through the 
fog, you can barely make out the beacon of a lighthouse to the northeast.
EndText
    );
    set("exits", ([
    "southwest" : M_ROOM+"wharf/wharf1.c",
    "west" : M_ROOM+"wharf/path2.c",
    ]) );
    set("item_desc", ([
    "fog" : "It's not as thick back here.\n",
    "shrubs" : "They are tall and woody, with small, hardy leaves.\n",
    "vines" : "They are thick and waxy green, and very, very tough.\n",
    "poison ivy" : "It growns in thick clumps withing the shrubs and thorns.\n",
    "ivy" : "It growns in thick clumps withing the shrubs and thorns.\n",
    "cups" : "They are old, and their print has faded.\n",
    "coffee cups" : "They are old, and their print has faded.\n",
    "coffee cups" : "They are old, and their print has faded.\n",
    "refuse" : "It is old, and its print has faded.\n",
    "beacon" : "It looks as though it may be fairly close.\n",
    "beacon" : "It looks as though it may be fairly close.\n",
    ]) );
    set("smell", ([
    "default" : wrap("The amell of salty sea air and stench of decomposing "+
        "organic material is pungent enough to make your eyes water."),
   	]) );
}

/* EOF */