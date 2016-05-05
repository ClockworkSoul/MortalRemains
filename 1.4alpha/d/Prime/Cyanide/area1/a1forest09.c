// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Ruined Outpost");
    set("long", wrap("You are on the top inside a small, ruined "+
	"outpost. Most of the stone battlements are intact, though "+
	"are obviously hundreds of years old. The wall to the "+
	"south has been destroyed, creating the sole exit. The "+
	"position of the outpost, on the edge of a huge cliff, "+
	"allows a breathtaking view of the ocean to the north, "+
	"and the a huge, majestic waterfall to the east."));
    set("exits", ([
      "south" : AREA1("a1forest11.c"),
    ]));
    set("item_desc", ([
      "outpost" : "You're standing in it.\n",
      "battlements" : "A low stone wall, designed to protect "+
      "defenders.\n",
      "wall" : "It looks to have been shattered by some kind of "+
      "projectile.\n",
      "ocean" : "Miles of rough waters, with no land in sight.\n",
      "waterfall" : wrap("It is about a half mile to the east. Its "+
	"source lies at about about 100 feet below you in "+
	"altitude, and falls another four hundred feet or so "+
	"below that, crashing in the ocean below."),
    ]) );
    set("search_desc", ([
      "ocean" : "Good fucking luck!\n",
      "waterfall" : "Want a barrel to go over it in?\n",
    ]) );
}

/* EOF */
