#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects", ([ "minauros" : BAATOR+"monsters/minauros" ]));
    set ("light", 1) ;
    set ("long",
      "This is the third layer of Baator.\n"+
      "You are in the sinking city of Minauros itself.\n"+
      "You have entered the throne room of minauros himself.\n");
    set ("short","Sinking city of Minauros");
    set ("exits", ([   
      "south" : BAATOR+"minauros/city29.c",
      "west" : BAATOR+"minauros/city21.c"
    ]));
    reset();
}


