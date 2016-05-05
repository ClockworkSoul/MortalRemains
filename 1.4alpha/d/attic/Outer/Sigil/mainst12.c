#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
 set("long", @ENDLONG
You stand in the seedy, run-down section of town known as the Hive
Ward in Sigil.  This is probably the least appealing section of 
Main Street you have been on.
ENDLONG
  );
  set("short", "Main Street, Hive Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"gatehouse.c",
	"east" : SIGIL+"mainst13.c",
	"west" : SIGIL+"mainst11.c" ]));
}
