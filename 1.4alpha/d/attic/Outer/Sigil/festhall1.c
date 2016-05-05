#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "djheknlarr" : "/d/Outer/Sigil/monsters/djheknlarr" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Civic Festhall. \n"+
"A place to relax.\n") ;
     set ("short", "Civic Festhall") ;
     set ("exits", ([
	    "north" : SIGIL+"festhall.c" ]));       
}
