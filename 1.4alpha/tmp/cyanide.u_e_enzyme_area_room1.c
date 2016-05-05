#include "/u/e/enzyme/include/area.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set ("light", 1);
    set ("author", "enzyme");
    set("short", "A cold and dark mausoleum");
    set("long", (
	" You have entered what appears to be an ancient mausoleum dedicated to\n"+
	" a heroic architect by the name of Zanzibar. The walls and ceilings are\n"+
	" made of marble that has cracks due to the passage of time. The air feels very\n"+
	" damp. Was there just something moving in that corner?\n"));
    set ("item_desc",  ([
      "chamber" : "A cramped chamber.",
      "corner" : "You thought you just saw something, but now you are not so sure.",
      "mausoleum" : "The cramped marble building you are entering.",
      "ancient mausoleum" : "The cramped marble building you are entering.",
      "building" : "It appears to be a mausoleum to burry people in.",
      "marble building" : "A mausoleum.",
      "cramped building" : "This building doesn't look very big.",
      "cramped marble building" : "Why dont you just use 'look'.",
      "something" : "It must have been your imagination, or wasn't it?",
      "crack#cracks" : "Time tends to deteriorate marble like this.",
      "substance#mineral substance" : "It looks like marble.",
      "marble" : "A hard mineral substance that can be polished and is quite sturdy.",
      "cracked marble" : "Marble tends to crack over time.",
      "wall#walls" : "The walls are filled with cracks due to the passing of time.",
      "ceiling#ceilings" : "The ceilings keep out the light.",
      "air" : "Unless you are a god, you can't see air!",
      "damp air" : "The air here feels slightly damp.",
    ]) );
    set("exits", ([
      "east" : PATH+"room2.c",
    ]));
}
