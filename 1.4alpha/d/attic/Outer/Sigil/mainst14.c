#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Main Street, Hive Ward.");
 set("long", @ENDLONG
You are on Main Street in the Hive Ward of Sigil.  This is probably the
bad side of town, judging from the seedy, run-down appearance of everything
here.
ENDLONG
) ;
     set ("exits", ([
	"east" : SIGIL+"mainst15.c",
	"west" : SIGIL+"mainst13.c" ]));
}
