#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "Maldomini, the seventh layer of Baator.\n"+
      "Buildings lie to the east and west,\n"+
      "The street continues north and south.\n");
    set ("short","Grenpoli, Maldomini, the seventh hell.");
    set ("exits", ([
      "north" : BAATOR+"maldomini/gren3.c",
      "south" : BAATOR+"maldomini/gren10.c",
      "east" : BAATOR+"maldomini/gren7.c",
      "west" : BAATOR+"maldomini/gren5.c"]));
    reset();
}
