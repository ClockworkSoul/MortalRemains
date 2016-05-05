#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain10.c",
      "east" : BAATOR+"avernus/plain12.c",
      "south" : BAATOR+"avernus/plain15.c",
      "north" : BAATOR+"avernus/plain7.c"
    ]));
    set("objects" , ([ 
      "black1" : BAATOR+"monsters/black_abishai",
      "black2" : BAATOR+"monsters/black_abishai",
      "black3" : BAATOR+"monsters/black_abishai",
      "green1" : BAATOR+"monsters/green_abishai",
      "green2" : BAATOR+"monsters/green_abishai",
      "red" : BAATOR+"monsters/red_abishai"
    ]));
    reset();
}
