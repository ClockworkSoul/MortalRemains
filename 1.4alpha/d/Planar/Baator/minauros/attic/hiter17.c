#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in the middle of a city of chains.\n"+
"Chains reach into the skies and even the buildings themselves.\n"+
"Are fashioned from this odd material.\n");
set ("short","Jangling Hiter, city of chains");
     set ("exits", ([   
      "east" : BAATOR+"minauros/hiter18.c",
      "north" : BAATOR+"minauros/hiter12.c",
  "south" : BAATOR+"minauros/hiter22.c"]));
reset();
	}


