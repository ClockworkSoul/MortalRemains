#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
      "east" : BAATOR+"minauros/hiter9.c"
    ]));
    reset();
}

int reset(){    
    object ob;

    ::reset();
    seteuid(getuid()) ;  

    if (present("kyton", this_object()) ) return 1;

    ob = clone_object(BAATOR+"monsters/kyton");
    ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    ob->move(this_object());

    return 1;
}

