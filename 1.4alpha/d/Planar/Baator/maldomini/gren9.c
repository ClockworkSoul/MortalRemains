#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"You are in a grand court of Baator,\n"+
"Where the strong always persevere over the weak.\n"+
"The Judge's chambers are behind a curtain to the west.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
         "east" : BAATOR+"maldomini/gren10.c",
          "west" : BAATOR+"maldomini/gren8.c"]));
reset();
	}
