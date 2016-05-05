#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    set ("long", wrap( 
	"This is the third layer of Baator, in the Sinking City "+
	"of Minauros itself. There is a small healer's hut to "+
	"the north and to the west is a seedy pub called "+
	"\"The Fetid Pile\""+".") );
    set ("exits", ([   
      "north" : BAATOR+"minauros/city1.c",
      "south" : BAATOR+"minauros/city6.c",
      "west" : BAATOR+"minauros/city2.c"
    ]));
}


