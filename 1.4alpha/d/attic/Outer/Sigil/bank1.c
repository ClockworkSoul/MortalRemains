#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;


     void create() {
	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "estavan" : "/d/Outer/Sigil/monsters/estavan"]));
  
     set ("light", 1) ;
     set ("long","This is The record halls.\n"+
     "Darkwood's secretary has his office here.\n") ;
     set ("short", "Record hall.") ;
     set ("exits", ([
     "up" : SIGIL+"bank2.c",
     "down" : SIGIL+"bank.c" ]) ) ;
reset();
}
