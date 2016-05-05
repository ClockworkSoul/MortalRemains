#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set("long", @EndLong
You have entered the water-filled lair of Shakar, the black dragon; a cave 
carved deep into the black volcanic glass cutting through this region. To 
the east is a small hole is the back of the cave, perhaps leading to 
another chamber.
EndLong
    );
    set ("exits", ([     
      "east" : BAATOR+"minauros/bog27.c",
      "west" : BAATOR+"minauros/bog27.c"
    ]));
    set("pre_exit_func", "east");
    reset();
}

void populate() {
    object ob;
    seteuid(getuid());

    ob = clone_object(BAATOR+"monsters/shakar.c");
    if (ob) ob->move(TO);

    return;
}

int east() {
    if (present("shakar", TO)) {
	write("Shakar slaps you with her tail!\n");
	say("Shakar slaps "+TPN+" with her tail!\n");
	TP->move_player(BAATOR+"minauros/bog27.c", "SNEAK");
	return 1;
    }

    return 0;
}

/* EOF */
