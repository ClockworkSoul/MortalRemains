// Fixed by Cyanide - 11/26/1998 10:46:15 PM 

#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Asmodeus") ;
    set ("long", "The Powerful Lord of the Ninth Hell.\n"+
      "There can be no question that Asmodeus is the most\n"+
      "handsome of all arch-fiends as well as being the\n"+
      "strongest and most cunning..\n") ;
    set ("id", ({ "asmodeus", "lord", "baatezu"}) ) ;
    set("prevent_summon", 1);
    set_name ("asmodeus") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    set_align("le");
    enable_commands() ;
    set("stat", ([
      "strength" : 25,
      "constitution" : 24,
      "dexterity" : 22,
      "intelligence" : 20,
      "wisdom" : 22,
      "charisma" : 23
    ]) );
    set_living_name("asmodeus") ;
    set_size(13);
    set ("thac0", 1);
    set ("base_ac", -7);
    set ("armor_class", -7);
    set ("damage", ({ 1,5 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 4);
    set ("magic_resist", 90);
    set ("mage_spells", ({ "stoneskin", "fireshield", "swarm", 
      "timestop",  "disjunction", "wilting", "prismsphere" }) );
    set ("max_sp", 3000);
    set ("spell_points", 3000);
    set ("resist_type", ([ "cold" : 0, "poison" : 0, "fire" : 0 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    set_skill("Clubbing Weapons", 2, "Strength");
    set_skill("One Weapon Style", 2, "Strength");
    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1 -> move (this_object()) ;
    arm(ITEM+"rubyrod.c");
    set ("special", 20);
    set_level(44);
    set("wealth", 100000);
}

void init(){
    ::init();
    command ("cast prismsphere");
    command ("wield rod");
}


void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;
    if (this_object()->query("power_delay") || this_object()->query("spell_points")<80) {
	return 0;
    }else{	
	ob = (present("#STONESKIN#", this_object()));
	if ( (ob) || (this_object()->query("wealth") < 1000)){
	    ob = (present("#FIRE_SHIELD#", this_object()));
	    if (ob){
		switch (random(5)){
		case 0 : command("cast timestop");break;
		case 1 : command("cast swarm at "+
		      (query_current_attacker())->query("name"));break;
		case 2 : command("cast wilting at "+
		      (query_current_attacker())->query("name"));break;
		case 3 : command("cast disjunction");break;
		case 4 : command("cast prismsphere");break;
		}
	    }else{
		command("cast fireshield cold");
	    }
	}else{
	    command("cast stoneskin");
	}
    }
}
