#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
set ("objects", ([ "milori" : "/d/Outer/Sigil/monsters/milori" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are on Hull Road in the Clerk's Ward of Sigil.
The Festive Civic Festhall looms to your west.
ENDLONG
  );
  set("short", "Hull Road, Clerk's Ward.");
     set ("exits", ([
	"north" : SIGIL+"mainst8.c",
	"west" : SIGIL+"festhall.c" ]));
}
