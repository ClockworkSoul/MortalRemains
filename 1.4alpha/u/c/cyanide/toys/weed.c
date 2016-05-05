#include "/u/c/cyanide/debug.h"

inherit OBJECT;

#define DELAY 30

int run = 0;

void create() {
    seteuid(getuid());
    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("long", "Just a random weed, growing everywhere.\n");
    set("short", "a patch of weeds");
    set("id", ({ "weed", "weeds", "#WEED#" }) );
    call_out("runners", DELAY);
}

void init() {
    if (!present("#WEED#", TP)) {
	object ob = clone_object("/u/c/cyanide/toys/burr.c");
	ob->move(TP);
	tell_object(TP, wrap("As you walk through the weeds, some burrs "+
	    "stick to your clothing."));
	ob->start_count();
    }
    if (!run) call_out("runners", DELAY);
}

void runners() {
    int flag, i;
    string *vexits;
    mapping exits;

    flag = -1;

    seteuid(getuid());

    if (environment() && !living(environment())) {
	exits = environment()->query("exits");
	vexits = values(exits);
	for(i=0; i<sizeof(vexits); i++) {
	    object room = find_object_or_load(vexits[i]);

	    if (room) {
		if (!present("#WEED#", room) && !present("#BURR#", room)) 
		    flag = i;
	    }
	}
    } else {
	if (!environment()) run = 1;
    }

    if (flag == -1) {
	run = 1;
    } else {
	object burr = clone_object("/u/c/cyanide/toys/burr.c");
	burr->move(find_object_or_load(vexits[flag]));
	burr->start_count();
	DEBUG("Runners going to "+vexits[flag]+"\n");
    }
}
