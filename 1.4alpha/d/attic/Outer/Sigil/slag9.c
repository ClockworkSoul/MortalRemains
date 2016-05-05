#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "parakk" : "/d/Outer/Sigil/monsters/parakk" ]) );
	reset();
     set ("light", 1) ;
  set("short", "In The Slags.") ;
  set("long", @ENDLONG
You stand in the slags, knee-deep in trash and other foul-smelling
matters.  This place is a breeding ground for disease.. and rats.
ENDLONG
  );
     set ("exits", ([
     "north" : SIGIL+"slag6.c",
     "west" : SIGIL+"slag8.c" ]) ) ;
}
