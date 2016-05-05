#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    set("long", @EndLong
You are standing just outside the massive gates of the legendary Sinking
City of Minauros, cursed to slowly sink into the mire over all eternity. 
Here, horrific fiends drive unfortunate souls onto the bottomless bog to
find ever rarer stone to bolster the city's structures.
EndLong
    );
    set ("short","Before the Gates of Sinking city of Minauros");
    set ("exits", ([   
      "east" : BAATOR+"minauros/city16.c",
      "west" : BAATOR+"minauros/bog17.c"
    ]));
}

int reset(){
    object ob;
    int i;

    ::reset();
    seteuid(getuid()) ;  

    if (present("cornugon", this_object())) return 1;

    for (i=0; i < 3; i++) {    
        ob = clone_object(BAATOR+"monsters/cornugon");

        ob->set("chat_chance", 3);
        ob->set("chat_output", ({
            "The cornugon ignores you, sharpening his horns.\n",
            "The cornugon glances over at you for a second.\n",
            "The guard looks you up and down and chuckles to itself.\n",
            "The cornugon guard inspects its whip for signs of wear.\n",
            "The cornugon says [to you]: You got a cigarette, bub?"
        }) );
        ob->set("short", "a cornugon guard");
        ob->add("long", "It has been charged with defending these gates.\n");

        ob->move(this_object());
    }

    return 1;
}

