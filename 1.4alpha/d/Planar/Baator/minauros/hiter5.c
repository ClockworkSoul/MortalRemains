#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {
    ::create();    
    set ("exits", ([   
    "west" : BAATOR+"minauros/hiter4.c",  
    "south" : BAATOR+"minauros/hiter10.c"
    ]));
    reset();
}

int reset(){    
    object ob;
    ::reset();
    seteuid(getuid()) ;  

    if (present("kyton", this_object())) return 1;

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    return 1;
}

