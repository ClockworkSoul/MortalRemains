#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "hashkar" : "/d/Outer/Sigil/monsters/hashkar" ]) );
	reset();
     set ("light", 1) ;
set ("short", "Haskar's Office.");
  set("long", @ENDLONG
You stand in the rather plain and undecorated office of Hashkar
in the Sigil Courthouse.
ENDLONG
  );
     set ("exits", ([
	"west" : SIGIL+"court3.c" ]));
}
