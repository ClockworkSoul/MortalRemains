

#include <mudlib.h>

inherit "/std/portal.c";

void create() {
    set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("id", ({ "#PORTAL#" }) );
    set("destination", "/d/Outer/Sigil/alehousest.c");
    set("direction", "southwest");
    set("portalkey", "a magic shovel");

}


