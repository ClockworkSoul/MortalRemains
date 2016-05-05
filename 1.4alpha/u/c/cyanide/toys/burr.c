#include "/u/c/cyanide/debug.h"

inherit OBJECT;

#define DELAY 30

int flag = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "burr", "seed", "#BURR#" }) );
    set("long", "A small spiny seed.\n");
    set("short", "@@query_short");
    set("prevent_get", 1);
    set("prevent_clean", 1);
}

void start_count() {
    if (!flag) {
	flag = 1;
	call_out("do_grow", DELAY);
    }
}

string query_short() {
    if (environment() && living(environment()) )
	return "a small burr";

    if (TPN=="Cyanide") return "a magic burr (invisible)";
}

void init() { start_count(); }

void do_grow() {
    object plant;
    object env = environment(TO);

    if (living(env)) {
	if (!present("#BURR#", environment(env)) &&
	  !present("#WEED#", environment(env)) ) {
	    tell_object(env, "The burr falls off and dissapears.\n");
	    set("id", ({ "#BURR#" }) );
	    flag = 0;
	    env = environment(environment());
	    move(env);
	    return;
	} else {
	    call_out("do_grow", DELAY);
	}
    }

    if (env) {
	plant = clone_object("/u/c/cyanide/toys/weed.c");
	if (plant) {
	    DEBUG("New weeds in "+base_name(environment())+"\n");
	    tell_room(env, "You notice a fresh patch of weeds nearby.\n");
	    plant->move(env);
	    remove();
	}
    }
}

/* EOF */
