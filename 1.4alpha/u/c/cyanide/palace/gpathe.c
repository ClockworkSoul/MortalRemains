#include "main.h"

inherit MAIN+"/gardenstd.c";

void create() {
    ::create();
    set("short", "A Garden Path");
    set("long", @EndLong
You are standing on a beautiful garden path of small crushed white
stones flanked by beautiful and fragrant flowering shrubs, each with
dozens of vividly colored flowers the size of dinner plates. To the
south there appears to be a fountain of some sort, and to the west,
that garden path continues into an intersection. You can reenter the
palace to the east, or wander into the garden to the north.
EndLong
    );
    set("exits", ([
      "north" : MAIN+"/garden01.c",
      "south" : MAIN+"/gfountain.c",
      "west" : MAIN+"/cgarden.c",
      "east" : MAIN+"/spireante.c",
    ]) );
    set("item_desc", ([
      "shrubs" : "The huge flowers appear to conceal "+
      "thousands of small sharp thorns.\n",
      "stones" : "They don't appear to be native to this region.\n",
      "flowers" :wrap( "Upon closer examination, you "+
	"obervea ring of tiny, but very sharp teeth near "+
	"the center of the flowers."),
      "fountain" : "The trees around it conceal it too much.\n", 
    ]) );
}

/* EOF */
