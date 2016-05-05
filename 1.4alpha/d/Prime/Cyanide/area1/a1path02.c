/*
** File:
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "cyanide");
    set("forbidden", 1);
    set("light", 1);
    set("long", @EndText
You are standing on a rocky, uneven path on the side of a mountain. 
Vegetation grows alongside the path, stunted by the salt-filled air and an
apparent lack of sunlight. To the north, the path seems to get much closer
to the ocean.
EndText
    );
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "north" : AREA1("a1view01.c"),
      "southwest" : AREA1("a1path01.c"),
    ]) );
    set("item_desc", ([
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
      "path" : "It leads to the north and southwest.\n"
    ]) );
    /*
	call_other(OBJ+"/Cy_board", "foo");
*/

    find_object_or_load(AREA1("a1path04.c"));
}

void reset() {
    /*
	    object ob;

	    ::reset();
	    seteuid(getuid());
	    if (present("#PORTAL#", TO)) return;

	    ob = clone_object(OBJ+"/cy_portal.c");
	    ob->move(TO);
	    return;
    */
}
/* EOF */
