#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "unity" : "/d/Outer/Sigil/monsters/unity" ]) );
	reset();
     set ("light", 1) ;
  set("short", "Gatehouse Cell.") ;
  set("long", @ENDLONG
You are in a dirty little cell in the Gatehouse.
ENDLONG
 );
     set ("exits", ([
         "east" : SIGIL+"gatehouse2.c" ]) ) ;
}
