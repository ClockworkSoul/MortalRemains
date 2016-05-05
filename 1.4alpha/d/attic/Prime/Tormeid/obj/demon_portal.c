
#include "../defs.h"

#include <mudlib.h>

inherit "/std/portal.c";

void create() {
    set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("id", ({ "#PORTAL#" }) );
  set("destination", DEMON_TEMPLE_START) ;
  set("direction", "north") ;
  set("portalkey", "#DEMON_TEMPLE#") ;

}


