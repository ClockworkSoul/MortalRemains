#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects" , ([ 	
      "black1" : BAATOR+"monsters/black_abishai",
      "black2" : BAATOR+"monsters/black_abishai",
      "black3" : BAATOR+"monsters/black_abishai"
    ]));
    set ("light", 1) ;
    set ("long",
      "This is the second layer of Baator.\n"+
      "You are in the great iron city of Dis.\n"+
      "The ground burns your feet as you walk.\n");
    set ("short","The Iron City of Dis");
    set ("exits", ([
      "south" : BAATOR+"dis/dcity14.c",
      "west" : BAATOR+"dis/dcity8.c"
    ]));
    reset();
}
