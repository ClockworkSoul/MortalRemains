// The Woodsman in Cyanide's Woods
// Cyanide has secretly named him "ranger rick".

#include "monsters.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("prevent_summon", 1);
    set("short", "a lonely woodsman");
    set("long", wrap("He is a tall, rugged-looking man with dark, "+
	"weathered skin and strikingly blue eyes."));
    set("id", ({ "ranger", "rick", "man", "woodsman" }) );
    set_skill("Axes", 3, "strength");
    arm(OBJ+"/wood_axe.c", "axe");
    set("CLASS", "warrior");
    set("class", "ranger");
    set_name("Rick");    // Ranger Rick.  Get it?
    set("stat", ([
      "strength" : 18,
      "constitution" : 17,
      "wisdom" : 13,
      "dexterity" : 15,
      "intelligence" : 10,
      "charisma" : 10,
    ]) );
    set("damage", ({ 1, 6 }) );
    set_align("cg");
    credit((random(100)+1)*100);
    set_verbs( ({ "swing at" }) );
    set("race", "human");
    set("gender", "male");
    set("moving", 1);
    set("speed", 1);
    set_level(15);
}


// Here, we make him hunt ants.
void init() {
    ::init();
    if (TP->query("race")=="ant")
	command("kill ant");
}

varargs int receive_damage(int i, string type, object c, int weap) {
    if (c && c->query("race")=="ant") return 0;

    return receive_damage(i, type, c, weap);
}

// Lets make him more lifelike.
void heart_beat() {
    move_around();
    continue_attack();
    command("bury corpse");
    command("get all");
}


/* EOF */
