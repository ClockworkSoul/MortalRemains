#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     seteuid(getuid()) ;
		set ("objects" , ([ "wyvern" : "/d/Outer/Sigil/monsters/wyvern" ]));
     reset();  
     set ("light", 1) ;
  set("short", "The Tower of the Wyrm.") ;
  set("long", @ENDLONG
Bones from the wyrm's cage high above litter the floor here.
ENDLONG
  ) ;
     set ("exits", ([
	"north" : SIGIL+"petitionerst2.c"]));
}
