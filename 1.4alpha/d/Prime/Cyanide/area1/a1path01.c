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
You are standing on a rocky, uneven path on the side of a mountain. 
Vegetation grows alongside the path, stunted by the salt-filled air and
apparent lack of sunlight. The path continues to a thick tangle of thorns
and trees to the south.
EndText
    );
    set("author", "cyanide");
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "south" : "/d/Prime/Central/room/wharf/path5.c",
      "northeast" : AREA1("a1path02"),
    ]) );
    set("item_desc", ([
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
    ]) );	
}

/* EOF */
