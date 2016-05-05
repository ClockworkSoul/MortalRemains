#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "The Caldera Rim");
    set("long", @EndText
You have at last reached the rim of the caldera which contains the Baatezu
city of Abriymoch. To the west you can see the city, showing red in the
seething glow of the lava below, suspended above the caldera by dozens of
massive iron chains. Below you and to your east, a treacherous path winds
down the face of the volcano.
EndText
    );
    set("item_desc", ([        
      "bridge" : "It crosses the space between the rim of the volcano "+
      "and the city. It seems\nto have been carved from black volcanic "+
      "basalt.\n",
      "city" : "It is directly to your west.\n",
      "chains" : "Each link is at least 30 feet in length and "+
      "must weigh tons.\n",
      "caldera" : "The mouth of the volcano is several "+
      "meters wide.\n",
      "volcano" : "It is truly massive.\n",
      "rim" : "It is the edge of the volcano caldera which holds the city.\n",
      "edge" : "It is the edge of the volcano caldera which holds the city.\n",
      "path" : "Though dangerous, it seems to be the only way down.\n",
    ]) );
    set("exits", ([
      "west" : PHLEGETHOS+"out02.c",
      "east" : PHLEGETHOS+"out04.c"
    ]) );
    reset();
}
