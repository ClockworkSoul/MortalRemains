// 24 Cyanide 99
// Cyanide made this not so much for functionality, as
// for the fact that he thought it would just be neat.

#include "/u/c/cyanide/debug.h"
#include <teleport.h>
#include "central.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("long", wrap(
	"You are standing within a large, modern arena, used for "+
	"everthing from sporting events to grudge matches.\n"+
	"The concrete floor here seems to be unusually stained "+
	"with blood, despite repeated cleanings."
      ) );

    set("exits", ([
      "north" : M_ROOM+"road1_0.c",
    ]) );
    set("no_teleport", NO_IN_OR_OUT);
    set("author", "cyanide");
    set("light", 1);
    set("short", CITY_NAME+" Arena");
    set("pre_exit_func", ([
      "north" : "in_combat",
    ]) );
}

int in_combat() {
    if (!TP->query_current_attacker()) {
	return 0;
    }

    write("You can't leave the arena while in combat!\n");
    return 1;
}

int receive_object(object ob) {
    if (!userp(ob)) return 1;

    if (base_name(environment(ob)) != M_ROOM+"road1_0")
    {
	tell_object(ob, "You may only enter the arena from the street!\n");
	return 0;
    }

    return 1;
}
/* EOF */
