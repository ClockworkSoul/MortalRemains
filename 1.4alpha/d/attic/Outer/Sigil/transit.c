#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"Here you can procure transit to many of\n"+
"The more useful locations in sigil.\n");
set("short", "Tea Street Transit");
     set ("exits", ([
	"south" : SIGIL+"mainst10.c" ]));
}
