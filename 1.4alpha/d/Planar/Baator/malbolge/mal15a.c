#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the sixth layer of Baator.\n"+
      "You are in one of the many vast towers\n"+
      "of this layer.\n"+
      "A central tower rises above the rest.\n"+
      "Walkways connect the towers at this level.\n"
    );
    set ("short","Malbolge, the sixth hell of Baator.");
    set ("exits", ([
      "down" : BAATOR+"malbolge/mal15.c",
      "southwest" : BAATOR+"malbolge/mal20a.c",
      "northwest" : BAATOR+"malbolge/mal8a.c"]));
    reset();
}

int reset(){
    object ob1;
    seteuid(getuid());
    ::reset();
    if (present("fiend", this_object())) return 1;
    ob1=clone_object(BAATOR+"monsters/pit_fiend.c");
    ob1->move(this_object());
    ob1->set("aggressive", 9);
    return 1;
}
