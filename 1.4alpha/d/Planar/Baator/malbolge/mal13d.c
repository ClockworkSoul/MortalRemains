#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the sixth layer of Baator.\n"+
      "You are on top of the tower of the lord of the sixth,\n"+
      "Malagard. Fear for your skin, mortal.\n");
    set ("short","Malbolge, the sixth hell of Baator.");
    set ("exits", ([
      "down" : BAATOR+"malbolge/mal13c.c"]));
    reset();
}

int reset(){
    object ob1;
    seteuid(getuid());
    ::reset();
    if (present("malagard", this_object())) return 1;
    ob1=clone_object(BAATOR+"monsters/malagard.c");
    ob1->move(this_object());
    return 1;
}
