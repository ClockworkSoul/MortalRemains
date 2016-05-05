#include <mudlib.h>
#include "baator.h"

inherit ROOM ;
object drake ;

void reset() {
    if (!drake)
    {
	drake = clone_object(BAATOR+"monsters/shadowdrake") ;
	drake ->move(TO) ;
    }
    ::reset() ;
}           

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the fifth layer of Baator.\n"+
      "You are along the banks of the fetid.\n"+
      "River Styx, the river of forgetfulness.\n");
    set ("short","River Styx, Stygia");
    set ("exits", ([
      "north" : BAATOR+"stygia/tcity16.c",
      "southeast" : BAATOR+"stygia/styx4.c",
      "northwest" : BAATOR+"stygia/styx2.c"]));
    reset();
}
