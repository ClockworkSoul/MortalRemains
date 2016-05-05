#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "alisohn" : "/d/Outer/Sigil/monsters/alisohn" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Warden's Office. \n"+
"This is where the Factol does her business.\n") ;
  set("short", "Factol's Office, Sigil Prison.") ;
     set ("exits", ([
	   "down" : SIGIL+"prison2.c" ]));       
}
