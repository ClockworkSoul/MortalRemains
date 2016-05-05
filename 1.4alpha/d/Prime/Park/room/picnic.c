#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A picnic area");
  set("long", wrap(
"Picnic tables are scattered throughout this area. They are painted bright "+
"red and are able to seat six people at once. Several ant hills lie below "+
"the tables, and you notice many ants darting about in search of crumbs."
     ) );
  set("item_desc", ([
    "picnic table" : "The picnic tables are bright red in color.\n",
    "picnic tables" : "The picnic tables are bright red in color.\n",
    "table" : "Each table can seat six people.\n",
    "tables" : "Each table can seat six people.\n",
    "ant hills" : "Ants dart in and out of the hills.\n",
    "ant hill" : "Ants dart in and out of the hill.\n",
    "hills" : "The ant hills are made of sand.\n",
    "hill" : "This ant hill is made of sand.\n",
    "ants" : "The ants are black in color and quite small.\n",
    "ant" : "This ant is black in color and quite small.\n",
    "crumbs" : "Small crumbs litter the ground.\n",
    "crumb" : "An ant carries a large crumb back to the hill.\n",
    ]) );
  set("smell", "You smell the fragrant flowers from the nearby gardens.\n");
  set("listen", "You hear only the chirping of nearby birds.\n");
  set("exits", ([
    "west" : P_ROOM+"path8.c",
    "south" : P_ROOM+"path4.c",
    "northeast" : P_ROOM+"orchard2.c",
    ]) );
  set("objects", ([
    "ant" : P_MON+"ant.c",
    "bee" : P_MON+"bee.c",
    ]) );
  reset();
  }
