

#include <mudlib.h>

inherit "/std/portal.c";

void create() {
set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
	set("id", ({ "#PORTAL#" }) );
    set("destination", "/d/Outer/Baator/avernus/ave1.c");
    set("direction", "south");
	set("portalkey", "severed arm");
 
   }

 
