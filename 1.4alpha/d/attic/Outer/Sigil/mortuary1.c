#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set ("objects", ([ "lykritch" : "/d/Outer/Sigil/monsters/lykritch" ]) );
    reset();
    set ("light", 1) ;
    set ("long",
      "You are in the basement of The mortuary of Sigil\n"+
      "Where The dead are kept.\n"+
      "There is a dark, shimmering portal in the corner.\n") ;
    set ("short", "Mortuary") ;
    set ("exits", ([
      "portal"	: SIGIL+"mortuary2.c",
      "up" : SIGIL+"mortuary.c" ]) ) ;
}
