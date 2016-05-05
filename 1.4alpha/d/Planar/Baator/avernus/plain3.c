#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"avernus/plain7.c",
      "west" : BAATOR+"avernus/plain2.c"
    ]));
    set ("objects" , ([ 
      "lemure1" : BAATOR+"monsters/lemure",
      "lemure2" : BAATOR+"monsters/lemure",
      "lemure3" : BAATOR+"monsters/lemure",
      "lemure4" : BAATOR+"monsters/lemure",
      "lemure5" : BAATOR+"monsters/lemure"
    ]));
    reset();
}
