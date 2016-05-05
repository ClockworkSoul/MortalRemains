#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;


     void create() {
	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "darkwood" : "/d/Outer/Sigil/monsters/darkwood"]));
  
     set ("light", 1) ;
     set ("long","This is Duke Rowan Darkwood's Private office.\n"+
     "Great bookshelves line the walls.\n") ;
     set ("short", "Darkwood's Office.") ;
     set ("exits", ([
     "down" : SIGIL+"bank1.c" ]) ) ;
reset();
}
