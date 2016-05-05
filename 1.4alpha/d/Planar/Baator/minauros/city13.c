#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    add("long", "You seem to have interrupted some kind of transaction.\n");
    set ("exits", ([   
    "north" : BAATOR+"minauros/city7.c"
    ]));
}

int reset(){    
    object ob;

    ::reset();
    seteuid(getuid()) ;  

    if (present("barbazu", this_object() )) return 1;

    ob = clone_object(BAATOR+"monsters/barbazu");
    ob->set("aggressive", 9);
    ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/barbazu");
    ob->set("aggressive", 9);
    ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/barbazu");
    ob->move(this_object());
    ob->set("aggressive", 9);
    return 1;
}

