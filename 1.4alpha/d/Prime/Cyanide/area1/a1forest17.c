// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Forest Path");
    set("long", wrap("This is a path winding through a dimly lit "+
	"forest. The path heads curves here, going from west to "+
	"southeast. One particularly large tree with some low "+
	"branches stands at the edge of the path."));
    set("exits", ([
      "west" : AREA1("a1forest11.c"),
      "southeast" : AREA1("a1forest18.c"),
      "climb" : AREA1("a1intree01.c"),
    ]) );
    set("item_desc", ([
      "forest" : "It is quite overgrown with old pine trees here.\n",
      "trees" : "Exclusively old fir trees.\n",
      "path" : "The path goes west and southeast.\n",
      "tree" : "Its branches hang low.\n",
      "branches" : "They would likely support your weight.\n",
      "branch" : "They would likely support your weight.\n",
    ]) );
    set("search_desc", ([
      "tree" : "It may be climbable.\n",
    ]) );
    set("smell", ([
      "default" : "The smell of pine trees fills the air.",
    ]) );
}

/* EOF */
