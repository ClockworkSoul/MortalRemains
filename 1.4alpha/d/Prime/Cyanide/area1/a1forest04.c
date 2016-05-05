// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Near a Chasm");
    set("long", wrap("Suddenly, the forest simply seems to stop, and "+
	"the path simply ends. Before you is a great bowl-shaped chasm, "+
	"apparently hundreds of feet deep. The wind whistles across it, "+
	"howling madly."));
    set("exits", ([
      "west" : AREA1("a1forest01.c"),
      "northeast" : AREA1("a1forest12.c"),
      "southeast" : AREA1("a1forest13.c"),
    ]) );
    set("item_desc", ([
      "forest" : "It is behind you.\n",
      "path" : "It ends because the chasm begins.\n",
      "chasm" : "You have no idea what created it, but it is unclimbable.\n",
      "bottom" : "You think you may see some trees down there...\n",
    ]) );
    set("search_desc", ([
      "chasm" : "You're not serious are you?\n",
    ]) );
}

/* EOF */
