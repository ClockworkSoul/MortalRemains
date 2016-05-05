

#include <mudlib.h>

inherit "/std/portal.c";

void create() {
    set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("id", ({ "#PORTAL#" }) );
    set("destination", "/d/Prime/Cyanide/area1/a1path02.c");
    set("direction", "west");
    set("portalkey", "a magic shovel");

}


