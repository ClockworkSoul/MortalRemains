#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
 set("objects", ([ "gazra" : BAATOR+"monsters/gazra" ]));
  set ("light", 1) ;
 set ("long",
"This is the fourth layer of Baator.\n"+
"You are at the court of fire.\n"+
"A towering pit fiend guards the portal to Stygia.\n");
set ("short","Abriymoch, Phlegethos the fourth hell");
     set ("exits", ([   
     "north" : BAATOR+"phlegethos/city13.c",
"portal" : BAATOR+"/stygia/tcity13.c"
]));
reset();
	}
