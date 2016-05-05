#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"avernus/plain10.c",
      "south" : BAATOR+"avernus/plain13.c",
      "north" : BAATOR+"avernus/plain5.c"
    ]));
    set("objects" , ([ 
      "black" : BAATOR+"monsters/black_abishai",
      "green" : BAATOR+"monsters/green_abishai",
      "red" : BAATOR+"monsters/red_abishai",
      "cornugon" : BAATOR+"monsters/cornugon",
      "spinagon" : BAATOR+"monsters/spinagon"
    ]));
    reset();
}
