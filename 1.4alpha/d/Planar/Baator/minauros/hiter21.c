#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    add("long", @EndLong
You have reached the end of a long alley, at the end of which is a massive
pile of garbage and refuse.
EndLong
    );
    set ("exits", ([   
        "north" : BAATOR+"minauros/hiter16.c"
    ]));
    reset();
}

int reset(){    
    object ob;

    ::reset();
    seteuid(getuid()) ;  

    if (present("osyluth", this_object()) ) return 1;

    ob = clone_object(BAATOR+"monsters/osyluth");
    if (ob) {
    ob->move(this_object());
    ob->set("aggressive", 9);
    }

    ob = clone_object(BAATOR+"monsters/osyluth");
    if (ob) {
    ob->move(this_object());
    ob->set("aggressive", 9);
    }

    return 1;
}
