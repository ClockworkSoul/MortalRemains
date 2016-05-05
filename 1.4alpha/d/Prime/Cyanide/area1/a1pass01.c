/*
** File:
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", @EndText
You are standing within a narrow pass somewhere in the
mountains. To your south is another opening in the pass wall.
EndText
    );
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "west" : AREA1("a1path03.c"),
      "south" : MAIN + "/o_clearing.c",
    ]) );
    set("item_desc", ([
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
      "path" : "It is a dead-end.\n"
    ]) );	
}

/* EOF */
