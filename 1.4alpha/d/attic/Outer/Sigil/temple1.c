#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
         set ("light", 1) ;
     set ("long",
"You are in the Shattered Temple.\n"+
	"The great tree Bouis Verdurous is here.\n") ;
     set ("short", "Shattered Temple") ;
     set ("exits", ([
     	"south" : SIGIL+"temple.c",
     	"west" : SIGIL+"temple2.c",
     	"east"	: SIGIL+"temple3.c" ]) ) ;
}
