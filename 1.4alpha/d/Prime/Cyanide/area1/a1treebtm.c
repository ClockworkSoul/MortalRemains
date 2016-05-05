// The forest in Cyanide's area.

#include <mudlib.h>
#include "cy.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "Beneath a Treehouse");
    set("long", wrap("You are standing below an old wooden "+
	"treehouse built high in the branches of a particularly "+
	"ancient and majestic oak. A shoddy rope ladder hangs down "+
	"the side of the tree."));
    set("exits", ([
      "north" : AREA1("a1forest07.c"),
      "east" : AREA1("a1forest10.c"),
      "up" : AREA1("a1treehouse.c"),
    ]) );
    set("item_desc", ([
      "ladder" : wrap("It may not hold your weight, but you could "+
	"try climbing it."),
      "oak" : "It is quite ancient.\n",
      "treehouse" : "You cannot possibly imagine who could have "+
      "built it here.\n",
    ]) );
    set("search_desc", ([
    ]) );
    set("smell", ([
    ]) );
}

/* EOF */
