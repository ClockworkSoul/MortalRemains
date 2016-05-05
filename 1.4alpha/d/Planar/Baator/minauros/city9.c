#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
This is the northern gatehouse for the main gate of Minauros, and also one
of the very few places in the city lacking in mud. This is where the on-duty
guards sworn to protect the city stay while on shift.
EndLong
    );
    set ("exits", ([   
      "south" : BAATOR+"minauros/city16.c"
    ]));
}

int reset(){    
    object ob1, ob2, ob3;

    ::reset();

    seteuid(getuid()) ;           

    if (present("barbazu", this_object())  ) return 1;
    ob1 = clone_object(BAATOR+"monsters/barbazu");
    ob1->move(this_object());
    ob2 = clone_object(BAATOR+"monsters/barbazu");
    ob2->move(this_object());
    ob3 = clone_object(BAATOR+"monsters/barbazu");
    ob3->move(this_object());

    ob1->set("protectors", ({ ob2, ob3 }));
    ob2->set("protectors", ({ ob1, ob3 }));
    ob3->set("protectors", ({ ob2, ob1 }));
    return 1;
}

