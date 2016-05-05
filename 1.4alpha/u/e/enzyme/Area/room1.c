inherit ROOM;
#include "area.h"

void create() {
    ::create();
    seteuid( getuid() );
    set ("light", 1);
    set ("author", "enzyme");
    set("short", "A cold and dark mausoleum\n");
    set("long", (
	" You have entered what appears to be an ancient mausoleum dedicated to\n"+
	" a heroic architect by the name of Enzyme. The walls and ceilings are\n"+
	" made of marble that has cracks due to the passage of time. The air feels very\n"+
	" damp. Was there just something moving in that corner?\n"));
    set ("item_desc",  ([
      "chamber" : "A cramped chamber.\n",
      "corner" : "You thought you just saw something, but now you are not so sure.\n",
      "mausoleum" : "The cramped marble building you are entering.\n",
      "ancient mausoleum" : "The cramped marble building you are entering.\n",
      "building" : "It appears to be a mausoleum to burry people in.\n",
      "marble building" : "A mausoleum.\n",
      "cramped building" : "This building doesn't look very big.\n",
      "cramped marble building" : "Why dont you just use 'look'.\n",
      "something" : "It must have been your imagination, or wasn't it?\n",
      "crack#cracks" : "Time tends to deteriorate marble like this.\n",
      "substance#mineral substance" : "It looks like marble.\n",
      "marble" : "A hard mineral substance that can be polished and is quite sturdy.\n",
      "cracked marble" : "Marble tends to crack over time.\n",
      "wall#walls" : "The walls are filled with cracks due to the passing of time.\n",
      "ceiling#ceilings" : "The ceilings keep out the light.\n",
      "air" : "Unless you are a god, you can't see air!\n",
      "damp air" : "The air here feels slightly damp.\n",
    ]));
    set("exits", ([
      "east" : PATH+"room2.c",
    ]));
}
