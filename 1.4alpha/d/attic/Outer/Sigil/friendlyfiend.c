#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "akin" : "/d/Outer/Sigil/monsters/akin" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You have entered The Friendly Fiend.\n"+
"a large warehouse of magical vesments and trinkets.\n") ;
     set ("short", "Friendly Fiend") ;
     set ("exits", ([
     "east" : SIGIL+"berkst.c" ]) ) ;
}
