#include "main.h"

inherit MAIN+"/gardenstd.c";

void create() {
    ::create();
    set("short", "A Garden Path");
    set("long", @EndLong
You are standing on a beautiful garden path of small crushed white
stones flanked by beautiful and fragrant flowering shrubs, each with
dozens of vividly colored flowers the size of dinner plates. To the
west, that garden path continues into an intersection. You can
reenter the palace to the west, and wander into the garden to the
north and south.
EndLong
    );
    set("exits", ([
      "north" : MAIN+"/garden02.c",
      "south" : MAIN+"/garden03.c",
      "east" : MAIN+"/cgarden.c",
      "west" : MAIN+"/preproom.c",
    ]) );
    set("item_desc", ([
      "shrubs" : "The huge flowers appear to conceal "+
      "thousands of small sharp thorns.\n",
      "stones" : "They don't appear to be native to this region.\n",
      "flowers" :wrap( "Upon closer examination, you "+
	"obervea ring of tiny, but very sharp teeth near "+
	"the center of the flowers."),
    ]) );
}

/* EOF */
