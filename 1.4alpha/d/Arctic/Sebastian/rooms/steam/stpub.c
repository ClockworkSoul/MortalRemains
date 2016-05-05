/*
	Um, big thanks to Cy for letting me use his code 
	structure for the pub.  Have a red devil on me.
*/

inherit PUB;

#include "../steamtown.h"
#include <mudlib.h>

void create() {
    ::create();
	set("author", "sebastian, with help.");
    set("light", 1);
	set("drink_types", ([
	"goblinbeer": 4,
	"frostwine":12,
	"dwarvenbrew": 26,
	"goblinbrew":-5,
	"wolfsbane":-15,
	"dragonsblood":-30
	]));
	set("short", "The Frosty Mug");
	set("long", @Foo
Ah, the smell of day old beer, and burning meat affronts you as
you open the door.  All manner of people populate the room,
squeezing into every possible chair.  The bartender is a burly
giff, a hippo with an attitude.  No bands ever play here, although
people are known to break into drunken song sometimes.
To see a selection of our drinks, just type menu.
To purchase a drink type buy <drink name>.
Foo
);
	set("item_desc", ([
	"people":"Ah, the unwashed masses, how bohemian.\n",
	"bartender":"A large hippo-man, a giff, with a nametag"+
	"that proclaims him to be 'Bob'.\n",
	"bob":"He's the bartender.  He's a hippo.  nuff said!\n",
	"giff":"A tall hippo shaped man, behind the bar, serving drinks.\n",
	"hippo":"Bob the bartender, is a giff. A hippo and quite"+
	"Buff lookin.\n"
	]));
    set("exits", ([
	"north":M_ROOM+"town3.c"
    ]) );
    set("safe", 1);
	set("listen","There once was an orc from Nantucket....\n");
	set("smell", "Mmm, malted hops and charred flesh, yummy.\n");
}

string drink(string str) {
    switch(lower_case(str)) {
	case "goblinbeer" : str = "Ick..tastes like a goblins tongue.\n"; break;
	case "frostwine":str = "As you down it, you shiver....yum.\n"; break;
case "dwarvenbrew":str = "Good LORD that's strong!\n"; break;
case "goblinbrew":str = "YUCK! If you ever wanted to taste a goblin's backside, here's a good substitute.\n"; break;
case "wolfsbane": str = "After you pound it, you wanna howl, AWOO!\n"; break;
case "dragonsblood": str = "You feel it burn your insides as you ingest it.\n"; break;
    default : str = "Damn, thats good.\n";
    }

    return str;
}


/* EOF */
