#include <mudlib.h>
#include "sigil.h"

inherit PUB ;

void create() {
         ::create();
        	seteuid(getuid());
	reset();
     set ("light", 1) ;
set("long", "some of the best drinks in sigil are found here.\n"+
"Commands are: menu , drink <drinkname> , powerheal <drinkname>\n");
     set ("short", "A Pub") ;
        set("short", "Fortune's Wheel");
     set ("exits", ([
        "north" : SIGIL+"fortune1.c",
        "south" : SIGIL+"mainst20.c" ]));
             
                   
	}
