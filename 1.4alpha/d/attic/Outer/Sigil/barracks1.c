#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
set ("objects", ([ "sarin" : "/d/Outer/Sigil/monsters/sarin"]));
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Office of the Factol of the Harmonium. \n"+
"This is where the Factol recieves his recruits.\n") ;
  set("short", "Factol's Office, Barracks.") ;
     set ("exits", ([
	   "down" : SIGIL+"barracks.c" ]));       
}
