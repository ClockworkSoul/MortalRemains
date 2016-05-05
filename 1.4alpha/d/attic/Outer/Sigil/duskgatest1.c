#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on Duskgate Road, one of the major streets in the City of Sigil.
You hear the sounds of a pub to your east.
ENDLONG
  ) ;
  set("short", "Duskgate Road, Market Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"duskgatest2.c",
	"south" : SIGIL+"mainst1.c",
	"east" : SIGIL+"chirpers.c",
	"west" : SIGIL+"healers.c" ]));
}
