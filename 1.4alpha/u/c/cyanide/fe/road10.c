#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create() {
    ::create();
    set("light", 1);
    set("short", "A concrete road");
    set("long", @Endtext
The road intersects with another trash filled road to the north.  A
modest building stands to the south.  Piles of garbage continue to
line the sides of the road.  A tall pole stands on the side pavement,
with swiveling camera mounted on the top.
Endtext
    );
    set("item_desc", ([
      "building" : "A neon sign reads [Post Office].\n",
      "garbage" : "Nothing seem to be too interesting about the trash.\n",
      "pole" : "It is about the height of an average street light.\n",
      "camera": "It is moving back and forth slowly... watching.\n",
    ]) );
    set("exits", ([
      "north" : ROOMS+"road05",
      "east"  : ROOMS+"road11",
      "south" : ROOMS+"post_office",
      /*
	  "west"  : ROOMS+"road09",
      */
    ]) );
    create_door("south", "north", "A wooden door", "open");
}
