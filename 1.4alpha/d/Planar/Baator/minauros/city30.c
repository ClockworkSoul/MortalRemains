#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    add("long", "A couple hamatula are gambling here.\n");
    set ("exits", ([   
    "east" : BAATOR+"minauros/city31.c"]));
}

int reset(){    
    object ob;

    ::reset();
    seteuid(getuid()) ; 

    if (present("hamatula", this_object())  ) return 1;

    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());
    ob = clone_object(BAATOR+"monsters/hamatula");
    ob->move(this_object());

    return 1;
}