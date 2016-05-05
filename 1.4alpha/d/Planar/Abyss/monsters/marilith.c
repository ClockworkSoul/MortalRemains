#include <mudlib.h>
#include "abyss.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Marilith") ;
    set ("long", "A half-snke, half humaonoid female torso with six arms and a bad attitude.\n");
    set("author", "ilzarion");
    set ("id", ({ "marilith", "tanar'ri" }) ) ;
    set_size(7);
    set_name ("marilith") ;
    set ("race", "tanar'ri");
    set ("gender", "female") ;
    enable_commands() ;
    set_living_name("marilith") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("magic_resist", 70);
    set("weap_resist", 2);
    set("stat/constitution", 15);
    set("stat/strength", 20);
    set ("base_ac", -9);
    set ("armor_class", -9);
    set("natt", 5);
    set("CLASS", "warrior");
    set ("damage", ({ 2,12 }) ) ;
    set ("weapon_name", "claws") ;
    set_skill("Long Blades", 1, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;
    set_skill("Two Weapon Style", 2, "Strength");
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set("special", 3);
    set_level(12);
    arm(ABYSS+"items/marysword.c");
    arm(ABYSS+"items/marysword.c"); 
}

void init(){
    ::init();
    command("wield sword");
    command("wield sword 2");
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();

    if (this_object()->query_hit(ob)) {	

	ob->receive_damage(((random(20)+5)), "crushing");
	tell_object(ob, "You are constricted by the marilith's tail!\n");
	say("The marilith's tail coils around "+ob->query("cap_name")+
	  "!\n", ({ ob }) );
    }
}
