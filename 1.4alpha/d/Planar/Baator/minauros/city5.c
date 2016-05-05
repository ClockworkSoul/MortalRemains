#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "south" : BAATOR+"minauros/city11.c"
    ]));
}

int reset(){    
    object ob;

    ::reset();

    seteuid(getuid()) ;  
    if (present("hamatula", this_object())  ) return 1;

    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());
    ob->set("aggressive", 9);

    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());
    ob->set("aggressive", 9);
    return 1;
}

