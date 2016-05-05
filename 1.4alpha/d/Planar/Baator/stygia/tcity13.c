#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long",
      "This is the fifth layer of Baator.\n"+
      "You are in the chilling city of Tantlin.\n"+
      "The portal back to warmer layers of hell beckons you.\n");
    set ("short","Tantlin, Stygia");
    set ("exits", ([
      "portal" : BAATOR+"phlegethos/city18.c",      
      "north" : BAATOR+"stygia/tcity8.c"]));
    reset();
}
