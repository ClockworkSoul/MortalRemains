// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Forest");
    set("long", wrap("You are at the edge of a large and ancient "+
	"forest. Old oaks and pines tower over you, blocking out the "+
	"aleady meager sunlight. To the east, a path winds deeper into "+
	"the forest, and to the west a steep climb leads down. A north-south"+
	" path also intersects here."));
    set("exits", ([
      "north" : AREA1("a1forest03.c"),
      "down" : AREA1("a1climb01.c"),
      "south" : AREA1("a1forest02.c"),
      "east" : AREA1("a1forest04.c"),
    ]) );
    set("item_desc", ([
      "path" : "There are 4 of them, leading in each of the cardinal "+
      "directions.\n",
      "oaks" : "They are obviously quite ancient.\n",
      "pines" : "They are obviously quite ancient.\n",
      "trees" : "They are obviously quite ancient.\n",
      "climb" : "Probably worn out by erosion.\n",
    ]) );
    set("search_desc", ([
    ]) );
    set("smell", ([
      "trees" : "They smell like trees.\n",
      "oaks" : "They smell like pine trees.\n",
      "pines" : "They smell like oak trees.\n",
      "default" : "Ahh... the smell of fresh air!\n",
    ]) );
}

/* EOF */
