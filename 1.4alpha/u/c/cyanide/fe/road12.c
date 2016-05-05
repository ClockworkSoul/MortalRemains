#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create() {
  ::create();
  set("light", 1);
  set("short", "A concrete road");
  set("long", @Endtext
Garbage is piled up everywhere on this road.  An abandoned building
with broken windows is to the east.  An old fire hydrant is laying
down on its side on the pavement near the building.  A small side
street leads to the northeast.  A few light pieces of trash are blown
about by the wind, scattering all over the street.
Endtext
 );
  set("item_desc", ([
    "garbage" : "A lot of mechanical parts are gathered to the northeast.\n",
    "building" : "It is an apartment building that has seen better days.\n",
    "hydrant" : "A bent metal pipe still connects it to the street.\n",
    "trash" : "It floats around, being blown by the wind.\n",
    "windows" : "There are pieces of glass still hanging on some windows.\n",
  ]) );
  set("exits", ([
    "northeast" : ROOMS+"road06",
    "east"  : APT+"hall01",
    "south" : ROOMS+"road14",
    "west"  : ROOMS+"road11",
  ]) );
  create_door("east", "west", "An old wooden door with a metal frame", "locked");
}

