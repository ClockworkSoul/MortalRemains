#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on Main Street in Sigil's Clerk's Ward.
The Hall of Records lies to the south.
ENDLONG
  );
  set("short", "Main Street, Clerk's Ward.") ;
     set ("exits", ([
	"south" : SIGIL+"bank.c",
	"east" : SIGIL+"mainst10.c",
	"west" : SIGIL+"mainst8.c" ]));
}
