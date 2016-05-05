#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Main Street, Hive Ward.") ;
  set("long", @ENDLONG
You are on Main Street in the Hive Ward of Sigil.  This is probably
the bad side of town, judging from the seedy, run-down look of everything
here.
ENDLONG
  );
     set ("exits", ([
	"north" : SIGIL+"ylemtower.c",
	"south" : SIGIL+"mortuary.c",
	"east" : SIGIL+"mainst14.c",
	"west" : SIGIL+"mainst12.c" ]));
}
