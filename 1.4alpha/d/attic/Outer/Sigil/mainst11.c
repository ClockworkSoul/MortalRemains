#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in the Hive Ward of Sigil, on Main Street.
This part of town looks very seedy and run-down.  A nauseating smell
permeates the air, making you ill.
ENDLONG
  );
  set("smell", ([
   "default" : "The smell is coming from the south.\n",
  ]) ) ;
   set("short", "Main Street, Hive Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"hive.c",
	"south" : SIGIL+"slag2.c",
	"east" : SIGIL+"mainst12.c",
	"west" : SIGIL+"mainst10.c" ]));
}
