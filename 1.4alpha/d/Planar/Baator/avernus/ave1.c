#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the first layer of Baator\n"+
      "A vast battle plain lies to the west and a fortress to the east.\n");
    set ("short","Avernus");
    set ("exits", ([
      "south" : BAATOR+"avernus/plain4.c"]));
}
