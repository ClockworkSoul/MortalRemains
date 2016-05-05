#include <mudlib.h>
#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

inherit MONSTER;

void create() {
    object ob;

    ::create();
    enable_commands();
    set("short", "Alyson, the administrative assistant");
    set("long", wrap("This is the administrative assistant to "+
	"Dy-Mar, the Chief Financial Officer of the Macrosoft "+
	"Corporation. Her professional demeanor and stunning "+
	"good looks are betrayed by the rather large gun she "+
	"carries."
      ) );
    set("id", ({ "alyson", "executive", "assistant" }) );
    set("prevent_summon", 1);
    set("author", "cyanide");
    set_name("Alyson");
    set("gender", "female");
    set("attrib1", "perfectly groomed");
    set("race", "half-elf");
    set("stat", ([
      "strength" : 10,
      "intelligence" : 18,
      "charisma" : 18
    ]) );
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set_size(5);
    set("max_sp", 350);
    set("spell_points", 350);
    set("special", 5);
    set ("mage_spells", ({ "stoneskin", "necrobolt", "bolt" }) );
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set ("wealth", 1200);

    wear("/d/attic/Outer/Sigil/items/bracers5") ;
    arm("/d/class/wizard/general/obj/book") ;
    ob = clone_object (MS_WEAP("m_msnecro.c"));
    if (ob) {
	set_skill(ob->query("weapon_type"), 2, "strength");
	set("ammo", ([ ob->query("ammo_type") : 100 ]) );
	arm(ob);
    }

    set_skill("Unarmed", 2, "strength");

    set_level(12);
}

void init () {
    ::init();
    command("cast stoneskin");
}

// Cheating, I know.
int ammo_debit(int i) { return 1; }

int special_attack() {
    object ob;
    int sv; 
    string target;

    if (random(3)) return 0;
    if (query("cast_delay") || query("spell_points")<80 ) return 0;

    switch (random(3)){
    case 0 : command("cast necrobolt");break;
    case 1 : command("cast bolt");break;
    case 2 : command("cast coldcone");break;
    }

    return 0;
}


// Thanks Chronos!

void
receive_message(string Class, string message) {
    string name, msg;


    if (sscanf(message, "%s laughs.", name)==1)  {
	call_out("force_me", random(3) + 1, "say What are you laughing at, fucker?");
	return ;
    }
    if (sscanf(message, "%s pokes you in the tummy.", name) == 1 ||
      sscanf(message, "%s ruffles your hair.", name) == 1 
    ) {
	call_out("force_me", random(2) + 1, "do scowl, to "+lower_case(name)+" Cut that out.") ;
	return ;
    }
    if (sscanf(message, "%s has died.", name ) ==1) {
	call_out("force_me", random(2) + 1, "do shout Hey "+capitalize(name)+
	  "- thanks for your stuff!, get all from corpse, eat corpse") ;
	return ;
    }
}




/* EOF */
