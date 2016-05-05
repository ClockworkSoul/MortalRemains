#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	
     set ("light", 1) ;
  set("short", "Sigil Prison.") ;
  set("long", @ENDLONG
You are in the Sigil Prison - where all the malcontents are locked away.
ENDLONG
  );
     set ("exits", ([
         "up" : SIGIL+"prison2.c",
        "west" : SIGIL+"petitionerst1.c" ]));       
}
