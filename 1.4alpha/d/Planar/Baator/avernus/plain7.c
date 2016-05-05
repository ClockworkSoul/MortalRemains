#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain6.c",
      "east" : BAATOR+"avernus/plain8.c",
      "north" : BAATOR+"avernus/plain3.c",
      "south" : BAATOR+"avernus/plain11.c"]));
}
