#include <mudlib.h>
#include "baator.h"

inherit SHOP ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "Maldomini, the seventh layer of Baator.\n"+
      "A shack that serves as this city's shop.\n");
    set ("short","Grenpoli, Maldomini, the seventh hell.");
    set ("exits", ([
      "west" : BAATOR+"maldomini/gren6.c"]));
    reset();
}
