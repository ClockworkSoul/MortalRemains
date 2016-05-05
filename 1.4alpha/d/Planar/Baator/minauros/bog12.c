#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {
::create();
set ("exits", ([   
"west" : BAATOR+"minauros/bog11.c",
"east" : BAATOR+"minauros/bog13.c",  
"north" : BAATOR+"minauros/bog5.c",
"south" : BAATOR+"minauros/bog18.c"]));
reset();
}
