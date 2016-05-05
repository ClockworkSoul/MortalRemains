#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "On the Black Bridge");
    set("long", @EndText
You are standing near the middle of the vast stone bridge connecting the
city of Abriymoch with the edge of the volcanic caldera which holds it.
The bridge continues west toward the city and east toward the crater rim.
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
    ]) );
    set("exits", ([
      "west" : PHLEGETHOS+"out01.c",
      "east" : PHLEGETHOS+"out03.c"
    ]) );
    reset();
}
