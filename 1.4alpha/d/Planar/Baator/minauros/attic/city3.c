#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", wrap( 
	"This is the third layer of Baator, in the Sinking City "+
	"of Minauros itself. There is a small healer's hut to "+
	"the north and to the west is a seedy pub called "+
	"\"The Fetid Pile\""+".") );
    set ("short","Sinking city of Minauros");
    set ("exits", ([   
      "north" : BAATOR+"minauros/city1.c",
      "south" : BAATOR+"minauros/city6.c",
      "west" : BAATOR+"minauros/city2.c"
    ]));
}


