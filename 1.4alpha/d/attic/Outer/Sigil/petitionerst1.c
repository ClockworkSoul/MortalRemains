#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in Petitioner's Square, in the Lady's Ward of Sigil.
To the east is the prison.
ENDLONG
  );
  set("short", "Petitioner's Square, Lady's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"mainst18.c",
	"south" : SIGIL+"petitionerst2.c",
	"east" : SIGIL+"prison.c" ]));
}
