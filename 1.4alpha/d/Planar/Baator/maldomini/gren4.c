#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"maldomini/magesociety.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "Maldomini, the seventh layer of Baator.\n"+
      "Several baaetezu chant to those paying for magical energies.\n");
    set ("short","Grenpoli, Maldomini, the seventh hell.");
    set ("exits", ([
      "west" : BAATOR+"maldomini/gren3.c"
    ]));
}
