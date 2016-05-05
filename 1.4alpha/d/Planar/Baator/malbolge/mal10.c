#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the sixth layer of Baator.\n"+
      "You are on the rocky slopes of Malbolge,\n"+
      "Where brass fortresses protect the inhabitants from\n"+
      "The constantly shifting terrain.\n");
    set ("short","Malbolge, the sixth hell of Baator.");
    set ("exits", ([
      "northeast" : BAATOR+"malbolge/mal5.c",
      "southeast" : BAATOR+"malbolge/mal17.c"]));
    reset();
}

int reset(){
    object ob1;

    ::reset();
    if (present("pitfiend", this_object())) return 1;
    ob1=clone_object(BAATOR+"monsters/pit_fiend.c");
    ob1->set("aggressive", 9);
    ob1->move(this_object());
    return 1;
}
