#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "erin" : "/d/Outer/Sigil/monsters/erin" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Civic Festhall. \n"+
"In the Factol's chambers.\n") ;
     set ("short", "Factol's Chambers") ;
     set ("exits", ([
	    "east" : SIGIL+"festhall.c" ]));       
}
