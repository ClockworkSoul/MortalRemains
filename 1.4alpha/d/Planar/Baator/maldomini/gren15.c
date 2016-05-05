#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "Maldomini, the seventh layer of Baator.\n"+
      "Buildings lie to the north and south,\n"+
      "The street continues west.\n"+
      "East lies the path to the city of Malagard.\n");
    set ("short","Grenpoli, Maldomini, the seventh hell.");
    set ("exits", ([
      "north" : BAATOR+"maldomini/gren12.c",
      "south" : BAATOR+"maldomini/gren17.c",
      "east" : BAATOR+"maldomini/mal6.c",
      "west" : BAATOR+"maldomini/gren14.c"
    ]) );
}
