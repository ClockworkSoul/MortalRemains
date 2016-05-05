#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "us" : "/d/Outer/Sigil/monsters/us" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand in the slags, knee-deep in trash and other foul-smelling
matters.  This place is a breeding ground for disease.. and rats.
ENDLONG
  );
  set("short", "In The Slags.") ;
     set ("exits", ([
     "south" : SIGIL+"slag7.c",
     "north" : SIGIL+"slag1.c",
     "east" : SIGIL+"slag5.c" ]) ) ;
}
