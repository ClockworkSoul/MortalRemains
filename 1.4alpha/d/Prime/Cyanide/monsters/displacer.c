
// Cyanide's version of Ilzarion's displacer beast. ;)
// There is a "pack mentality" among them...

#include "monsters.h"

inherit "/obj/monster/displacer.c";

void create() {
    ::create();
    set("prevent_summon", 1);
    delete("aggressive");
}

void init() {
    object *obs = all_inventory(environment(TO));

    ::init();

    if (query("alpha")) obs = ({});
    for (int i=0; i<sizeof(obs); i++) {
	if (obs[i]->id("displacer beast") && 
	  obs[i]->query("alpha")) {
	    delete("moving");
	    obs[i]->add("followers", ({ TO }) );
	    obs[i]->add("protectors", ({ TO }) );
	    break;
	}
    }

    if (userp(TP) && !adminp(TP))
	if (!TP->query("invisible")) kill_ob(TP);
}

void die() {
    object *obs = ({});
    int i;

    if (query("alpha") && environment(TO)) {
	obs = all_inventory(environment());
	for (i=0;i<sizeof(obs);i++) {
	    if (obs[i]->id("displacer beast") && obs[i]!=TO) {
		AREA2("a1path04.c")->make_alpha(0);
		i = sizeof(obs);
	    }
	}
    }

    ::die();
}

void heart_beat() {
    continue_attack();
    unblock_attack();
    move_around();
    return;
}
