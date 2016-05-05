#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    add ("long", "It looks as though you've accidentally stumbled across "+
        "a very private\n"+"conversation.\n");
    set ("exits", ([   
    "south" : BAATOR+"minauros/city10.c"
    ]));
}

int reset(){    
    object ob;
    ::reset();

    if (present("hamatula", this_object())  ) return 1;

    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());

    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());
    return 1;
}

