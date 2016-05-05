#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    add("long", "Several hamatula are here, looking for some entertainment.\n");
    set ("exits", ([   
    "west" : BAATOR+"minauros/city32.c"
    ]));
}

int reset(){    
    object ob1, ob2, ob3;
    ::reset();
    seteuid(getuid()) ;  

    if (present("hamatula", this_object())  ) return 1;

    ob1 = clone_object(BAATOR+"monsters/hamatula");
    ob1->move(this_object());
    ob2 = clone_object(BAATOR+"monsters/hamatula");
    ob2->move(this_object());
    ob3 = clone_object(BAATOR+"monsters/hamatula");
    ob3->move(this_object());

    ob1->set("protectors", ({ ob2, ob3 }));
    ob2->set("protectors", ({ ob1, ob3 }));
    ob3->set("protectors", ({ ob2, ob1 }));
    return 1;
}

