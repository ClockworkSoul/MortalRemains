#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in the south of a city of chains.\n"+
"Chains reach into the skies and even the buildings themselves.\n"+
"Are fashioned from this odd material.\n");
set ("short","Jangling Hiter, city of chains");
     set ("exits", ([   
      "north" : BAATOR+"minauros/hiter18.c",
  "west" : BAATOR+"minauros/hiter22.c"]));
reset();
	}


