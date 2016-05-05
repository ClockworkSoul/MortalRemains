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
      "north" : BAATOR+"maldomini/gren1.c",
      "south" : BAATOR+"maldomini/gren6.c",
      "east" : BAATOR+"maldomini/gren4.c",
      "west" : BAATOR+"maldomini/gren2.c"
    ]) );
}
