#include <mudlib.h>
#include "main.h"
inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 1);
    set ("area_type", ([
      "black" : 2,
    ]) );
    set ("short", "Great Cavern");
    set( "long", @EndText
This is the center of a great cavern, carved out of the limestone.
Stalagmites and stalagtites of many sizes grow everywhere. The room
glows with a dim light provided by phosphorescent moss, and weird
shadows move all around you. A narrow path winds southwest among the
stalagmites, and another leads northeast.
EndText
    );
    set( "exits", ([
      "northeast" : MAIN+"/ftbridge.c",
      "southwest" : MAIN+"/ford.c",
    ]) );
    set ("item_desc", ([
      "stalagmites" : "Those are the ones pointing up, you think.\n",
      "stalagtites" : "Those are the ones pointing down, you think.\n",
      "moss" : "It is glowing with a soft yellow-green light.\n"+
      "It may warrant a closer look...\n",
      "path" : "It looks promising.\n",
      "shadows" : "They flow as if they're... alive.\n",
    ]) );
}

void reset() {
    object ob;

    ::reset();
    seteuid(getuid());
    if (present("slime", this_object())) return;
    ob = clone_object(MONST+"/slime.c");
    ob->move(TO);
    ob->set("moving", 1); 
}

int search (string str) {
    object ob;
    if (str=="moss") {
	ob = clone_object(MONST+"/slime.c");
	ob->move(TO);
	return 1;
    }
    return 0;
}
