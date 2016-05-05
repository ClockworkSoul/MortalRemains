

#include <mudlib.h>
#include <config.h>

inherit "/std/portal.c";

void create() {
    set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("id", ({ "#PORTAL#" }) );
	set("destination", "/d/Outer/Mountcelestia/Area1/meadow01.c");
	set("direction", "east");
	set("portalkey", "#CLASS_OBJECT#");
}


