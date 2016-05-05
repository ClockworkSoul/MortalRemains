#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Main Street, Lady's Ward.") ;
  set("long", @ENDLONG
You are on Main Street in the Lady's Ward of Sigil.
Petitioner's Square is to the south.
ENDLONG
  ) ;
     set ("exits", ([
	"south" : SIGIL+"petitionerst1.c",
	"east" : SIGIL+"mainst19.c",
	"west" : SIGIL+"mainst17.c" ]));
}
