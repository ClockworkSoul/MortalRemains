#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the fourth layer of Baator.\n"+
      "To the south is the city of Abriymoch in Phlegethos.\n"+
      "It is seated within an active volcano.\n"+
      "To the east is a path into the fiery layer.\n");
    set ("short","Abriymoch, Phlegethos the fourth hell");
    set ("exits", ([   
      "up" : BAATOR+"minauros/city21.c",
      "south" : BAATOR+"phlegethos/city20.c",
      "east" : BAATOR+"phlegethos/out01.c"
    ]) );
    reset();
}


