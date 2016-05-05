#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand in the Lower Ward of Sigil, on Main Street.
Alehouse Row is just north of here.
ENDLONG
  );
  set("short", "Main Street, Lower Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"alehousest.c",
	"south" : SIGIL+"berkst.c",
	"east" : SIGIL+"mainst16.c",
	"west" : SIGIL+"mainst14.c" ]));
}
