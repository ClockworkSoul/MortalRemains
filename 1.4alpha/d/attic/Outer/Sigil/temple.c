#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     seteuid(getuid());
     set ("objects", ([ "saure" : "/d/Outer/Sigil/monsters/saure" ]) );
     reset();          
     set ("light", 1) ;
  set("long", @ENDLONG
You are in the crumbling ruins of the once-great Shattered Temple of
Sigil.  It stands now only as a monument to a religion lost in the
folds of time.
ENDLONG
  );
  set("short", "Shattered Temple.");
     set ("exits", ([
     	"north" : SIGIL+"temple1.c",
     	"east"	: SIGIL+"alehousest.c" ]) ) ;
}
