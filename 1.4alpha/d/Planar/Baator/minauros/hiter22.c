#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/hiter17.c",
    "east" : BAATOR+"minauros/hiter23.c"
    ]));
    reset();
}

int reset() {
    object ob;

    ::reset();
    seteuid(getuid());

    if (present("kyton", this_object()) ) return 1;

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/kyton");
    if (ob) ob->move(this_object());

    return 1;
}

