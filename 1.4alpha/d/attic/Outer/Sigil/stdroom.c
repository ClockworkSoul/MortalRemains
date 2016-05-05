#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"You are in a very boring room which\n"+
"Needs a long description.\n") ;
     set ("short", "standard uncoded room") ;
     set ("exits", ([
     "north" : "/u/i/ilzarion/workroom.c" ]) ) ;
}
