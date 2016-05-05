#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {
    ::create();
    set ("exits", ([   
      "east" : BAATOR+"minauros/hiter2.c",  
      "south" : BAATOR+"minauros/hiter6.c"
    ]));
    reset();
}

int reset(){
    object ob1, ob2, ob3;
    ::reset();

    seteuid(getuid()) ;  
    if (present("kyton", this_object())) return 1;

    ob1 = clone_object(BAATOR+"monsters/kyton");
    ob1->move(this_object());
    ob2 = clone_object(BAATOR+"monsters/kyton");
    ob2->move(this_object());
    ob3 = clone_object(BAATOR+"monsters/kyton");
    ob3->move(this_object());

    return 1;
}

