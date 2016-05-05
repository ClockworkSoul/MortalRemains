// File:    ant_queen.c
// Prupose: The queen ant in Cyanide's forest,
// The queen ant!

#include "/u/c/cyanide/debug.h"
#include "monsters.h"

// The maximum # of live ants that can exist. When one
// dies, the queen will replace it.
#define MAX_ANTS 28

// The number of heart beats between egg layings.
// The greater the number, the less frequently eggs are laid.
#define LARVA_RATE 20

inherit MONSTER;

int hb = 0;

void create() {
    ::create();
    set("prevent_summon", 1);
    set("author", "cyanide");
    set("short", "the queen ant");
    set("long", wrap("A massive dark brown ant, her abdomen "+
	"grotesquely swollen with eggs. She snaps at you visciously,"+
	" waiting for you to come close enough, so she can tear "+
	"you to pieces."));
    set("id", ({ "ant", "queen", "queen ant", "giant ant" }) );
    set_name("queen ant");
    set("CLASS", "warrior");
    set("class", "fighter");
    set_size(20);
    set("stat", ([
      "strength" : 24,
      "constitution" : 20,
      "wisdom" : 3,
      "dexterity" : 13,
      "intelligence" : 1,
      "charisma" : 2,
    ]) );
    set_skill("Unarmed", 5, "strength");
    credit((random(20)+1)*1000);
    set("weapon_name", "mandibles");
    set_verbs( ({ "snap at", "bite", "chew on" }) ) ;   
    set("damage", ({ 8, 32 }) );
    set("damage_type", "slashing");
    set("base_ac", -1);
    set("race", "ant");
    set("gender", "female");
    set_level(30);
}


// Here, we make him hunt ants.
void init() {
    ::init();
if (wizardp(TP)) return;
    if ((string)TP->query("race")!="ant")
	command("kill "+( (string *)TP->query("id") )[0] );
}


// We drop a new ant every LARVA_RATE heartbeats.

void heart_beat() {
    int num;
    string str;
    object larva;

    switch(random(10)) {
    case 0..2 : str = "worker"; break;
    default : str = "drone"; break;
    }

    if (++hb >= LARVA_RATE) {
	hb = 0;

	// Get the current number of ants. The negative numbers
	// cut the the loaded (but not cloned) copy the mud keeps.
	num = sizeof(children(MON+"/worker.c")) - 1;
	num += sizeof(children(MON+"/drone.c")) - 1;
	if (num < MAX_ANTS) {
	    larva = clone_object(MON+"/"+str+".c");
	    if (!larva) DEBUG("ERROR IN QUEEN ANT'S CLONING FUNC!\n");
	    if (environment()) {
		tell_room(environment(), wrap("The queen lays an egg, "+
		    "which quickly hatches and develops into a "+
		    "full-grown "+str+"!"));
		larva->move(environment());
	    }
	}
    } // if (++hp >= LARVA_RATE)
    ::heart_beat();
}

/* EOF */
