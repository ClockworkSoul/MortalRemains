#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {
::create();
set ("exits", ([     
"south" : BAATOR+"minauros/bog17.c",
"west" : BAATOR+"minauros/bog9.c"]));
reset();
}
