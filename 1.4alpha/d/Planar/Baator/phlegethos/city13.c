#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
 set("objects", ([ "fierana" : BAATOR+"monsters/fierana" ]));
  set ("light", 1) ;
 set ("long",
"This is the fourth layer of Baator.\n"+
"You are at the court of fire.\n"+
"Fierana judges those who may pass.\n");
set ("short","Abriymoch, Phlegethos the fourth hell");
     set ("exits", ([   
     "north" : BAATOR+"phlegethos/city8.c",
   	     	  "south" : BAATOR+"phlegethos/city18.c"
   	     	  ]));
reset();
	}
