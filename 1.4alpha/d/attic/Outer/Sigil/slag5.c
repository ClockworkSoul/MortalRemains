#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "rat" : "/d/Outer/Sigil/monsters/rat" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand in the slags, knee-deep in trash and other foul-smelling
matters.  This place is a breeding ground for disease.. and rats.
ENDLONG
  );
  set("short", "In The Slags.") ;
     set ("exits", ([
     "north" : SIGIL+"slag2.c",
     "south" : SIGIL+"slag8.c",
     "east" : SIGIL+"slag6.c",
     "west" : SIGIL+"slag4.c" ]) ) ;
}
