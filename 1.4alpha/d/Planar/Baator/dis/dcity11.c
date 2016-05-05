#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"dis/dcity16.c",
      "west" : BAATOR+"dis/dcity10.c"]));
    reset();
}
