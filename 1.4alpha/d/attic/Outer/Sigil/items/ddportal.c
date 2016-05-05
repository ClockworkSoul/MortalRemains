

#include <mudlib.h>

inherit "/std/portal.c";

void create() {

    set("prevent_get", 1);
    set("prevent_clean", 1);
	set("id", ({ "#PORTAL#" }) );
    set("destination", "/d/class/warrior/deathdealer/rooms/ddguild.c");
    set("direction", "down");
	set("portalkey", "dragonarmor");
 
   }

 
