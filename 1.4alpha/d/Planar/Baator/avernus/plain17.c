#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("exits", ([
      "east" : BAATOR+"avernus/plain18.c",
      "north" : BAATOR+"avernus/plain13.c"
    ]));
    set("objects" , ([ 
      "barbazu" : BAATOR+"monsters/barbazu",
      "barbazu2" : BAATOR+"monsters/barbazu",
      "barbazu3" : BAATOR+"monsters/barbazu",
      "osyluth" : BAATOR+"monsters/osyluth"
    ]));
    reset();
}
