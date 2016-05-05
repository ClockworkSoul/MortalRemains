#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("light", 1) ;
    set ("exits", ([
      "west" : BAATOR+"avernus/plain7.c",
      "east" : BAATOR+"avernus/ave2.c",
      "south" : BAATOR+"avernus/plain12.c",
      "north" : BAATOR+"avernus/plain4.c"]));
}
