#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "karan" : "/d/Outer/Sigil/monsters/karan" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in a run down shack in the Hive Ward of Sigil that serves
as the home to the ChaosMen of Sigil.
ENDLONG
  );
   set("short", "Xaositic Headquarters.") ;
     set ("exits", ([
"north" : "/d/class/warrior/barbarian/rooms/barbguild.c",
     "south" : SIGIL+"mainst11.c" ]) ) ;
}
