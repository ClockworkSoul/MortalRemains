#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
        "south" : BAATOR+"avernus/plain5.c",
	    "east" : BAATOR+"avernus/plain2.c"
    ]));
	set ("objects" , ([ 
	"nupperibo1" : BAATOR+"monsters/nupperibo",
	"nupperibo2" : BAATOR+"monsters/nupperibo",
	"nupperibo3" : BAATOR+"monsters/nupperibo",
	"nupperibo4" : BAATOR+"monsters/nupperibo",
	"nupperibo5" : BAATOR+"monsters/nupperibo"
	]));
    reset();
}
