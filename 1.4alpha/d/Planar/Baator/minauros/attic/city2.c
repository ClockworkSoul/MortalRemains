#include <mudlib.h>
#include "baator.h"

inherit PUB;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("drink_types", ([
      "bloody kiss" : 10,
      "venomwine" : 15,
    ]) );
    set ("light", 1) ;
    set ("long", wrap(
	"You are in a seedy pub in Minauros, the Third Layer of "+
	"Baator, filled with all sorts of demonic rabble from "+
	"all parts of the multiverse. Tonight's menu features:\n"+
	"\n"+list()+"If you like, you may <buy> something, or "+ 
	"see the <menu>. We at the Fetid Pile strongly believe "+
	"that coffee is for the weak!"
      ) );
    set ("short", "The Fetid Pile");
    set ("exits", ([   
      "east" : BAATOR+"minauros/city3.c"
    ]));
}


string drink(string str) {
    switch(lower_case(str)) {
    case "bloody kiss" : str = "A peculiar taste, like real blood.\n"; break;
    case "venomwine" : str = "DAMN, thats disgusting!\n"; break;
    default : str = "Damn, thats good.\n";
    }

    return str;
}

/* EOF */   
