#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
    set ("exits", ([
	"east" : BAATOR+"avernus/fortbel2.c",
	"south" : BAATOR+"avernus/fortbel4.c"
	]));
}
