#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
    ::create();
    set ("short", "Land of Shadow");
    set( "long", @EndText
You are standing atop a steep cliff, looking west over a vast ocean. Far
below, the surf pounds at a sandy beach. To the south and eastare rolling
hills filled with eerie shadows. A path cut into the face of the cliff
descends toward the beach. To the north is a tall stone wall which ends at
the cliff edge. It was obviously built long ago, and directly north is a spot
where you could climb over the rubble of the decaying wall.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/cliff.c",
      "east" : MAIN+"/LOS02.c",
      "southeast" : MAIN+"/LOS03.c",
      "west" : MAIN+"/ocean.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

    set ("item_desc", ([
    ]) );
}

