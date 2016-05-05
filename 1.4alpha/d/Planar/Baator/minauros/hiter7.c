#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    add("long", "You appear to have reached a dead-end.\n");
    set ("exits", ([   
      "south" : BAATOR+"minauros/hiter12.c"
    ]));
    reset();
}

int reset() {    
    object ob;

    ::reset();
    seteuid(getuid()) ;  

    if (present("kocrachon", this_object())) return 1;

    ob = clone_object(BAATOR+"monsters/kocrachon");
    if (ob) {    
	ob->move(this_object());
	ob->set("aggressive", 9);
    }

    ob = clone_object(BAATOR+"monsters/kocrachon");
    if (ob) {    
	ob->move(this_object());
	ob->set("aggressive", 9);
    }

    ob = clone_object(BAATOR+"monsters/kocrachon");
    if (ob) {    
	ob->move(this_object());
	ob->set("aggressive", 9);
    }

    return 1;
}

