#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "fell" : "/d/Outer/Sigil/monsters/fell" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
@ENDLONG
This is the place where Fell the Tattoo Artist can affix
any design you like on your body in exchange for a few coins.

A sign hangs from the door reading, "Temporarily Closed."
ENDLONG
 );
  set("short", "Fell's Tattoo Parlor.") ;
     set ("exits", ([
	"east" : SIGIL+"duskgatest2.c"]));
}
