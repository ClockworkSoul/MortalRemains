// Shadowdrake.
// 1998 Apr 16   Created by Ilzarion
// 2000 Feb  2   Cleaned up by Cyanide

#include <mudlib.h>
#include <config.h>
#include "baator.h"

inherit MONSTER;

int set_age_level();

void create () {
    ::create() ;
    seteuid(getuid());

    set("prevent_summon", 1);
    set("stat/dexterity", 20);
    set("stat/strength", 22);
    set("stat/constitution", 25);
    set("short", "Shadowdrake");
    set("long", "This is a Styx River serpent.\n");
    set("id", ({ "shadowdrake", "dragon", "drake", "shadow" }) );
    set("special", 10);
    set("natt", 2);
    set("race", "dragon");
    enable_commands();
    set("damage_type", "slashing");
    set("weapon_name", "bony forked tail");
    set_verbs( ({ "slash", "slice", "smite" }) );
    set_verbs2( ({ "slashes", "slices", "smites" }) );
    set_name("shadowdrake");
    set_living_name("shadowdrake");
    set_age_level();
    set("wealth", (this_object()->query("hit_points")));
}


void special_attack() {
    object ob, acid;
    int sv, dmg;  

    seteuid(getuid()); 
    ob = this_object()->query_current_attacker();

    if (random(3) == 0) {    
    	say("The Shadowdrake coats "+ob->query("cap_name")+
    	    " in gobs of acid spittle!\n", ob);
    	tell_object(ob, "The Shadowdrake coats you in a bath of "+
    	    "acidic spittle!\n");
    	sv = ob->save_throw(-2);
    	dmg = random( (int)query("breathrandom")+(int)query("breathbonus") );
	if (sv){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob, "You dive out of the way!\n");
	    }else{
		acid = clone_object(BAATOR+"items/acidbreath.c");
		dmg /= 2;
		acid->move(ob);
		acid->begin(dmg);
	    }
	}
	if (sv == 0){
	    acid = clone_object(BAATOR+"items/acidbreath.c");
	    acid->move(ob);
	    acid->begin(dmg);
	}
    }else{
	say("The Shadowdrake sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "The Shadowdrake sinks it's teeth into your flesh!\n");
	ob->receive_damage((random(4)+36), "slashing", this_object(), 1);
    }

}

int set_age_level(){
    int age = (random(12)+1);
    if ((age == 12) && (random(2)))
        (age += random(5)+1);

    switch (age){

    case 1 :
	set("short", "Hatchling Shadowdrake");
	set("damage", ({ 3,17 }) );
	set("breathrandom", 8);
	set("breathbonus", 3);
	set("armor_class", 4);
	set_size(17);
	set("magic_resist", 10);
	set_level(3);
	break;
    case 2 :
	set("short", "Baby Shadowdrake");
	set("damage", ({ 4,18 }) );
	set("breathrandom", 12);
	set("breathbonus", 5);
	set("armor_class", 3);
	set_size(30);
	set("magic_resist", 15);
	set_level(5);
	break;
    case 3 :
	set("short", "Young Shadowdrake");
	set("damage", ({ 5,19 }) );
	set("breathrandom", 16);
	set("breathbonus", 6);
	set("armor_class", 2);
	set_size(40);
	set("magic_resist", 20);
	set_level(7);
	break;
    case 4 :
	set("short", "Juvenile Shadowdrake");
	set("damage", ({ 6,20 }) );
	set("breathrandom", 20);
	set("breathbonus", 7);
	set("armor_class", 1);
	set_size(49);
	set("magic_resist", 25);
	set_level(9);
	break;
    case 5 :
	set("short", "Young adult Shadowdrake");
	set("damage", ({ 7,21 }) );
	set("breathrandom", 24);
	set("breathbonus", 8);
	set("armor_class", 0);
	set_size(58);
	set("magic_resist", 30);
	set_level(11);
	break;
    case 6 :
	set("short", "Adult Shadowdrake");
	set("damage", ({ 8,22 }) );
	set("breathrandom", 28);
	set("breathbonus", 9);
	set("armor_class", -1);
	set_size(67);
	set("magic_resist", 35);
	set_level(12);
	break;
    case 7 :
	set("short", "Mature Shadowdrake");
	set("damage", ({ 9,23 }) );
	set("breathrandom", 32);
	set("breathbonus", 10);
	set("armor_class", -2);
	set_size(75);
	set("magic_resist", 40);
	set_level(13);
	break;
    case 8 :
	set("short", "Old Shadowdrake");
	set("damage", ({ 10,24 }) );
	set("breathrandom", 36);
	set("breathbonus", 11);
	set("armor_class", -3);
	set_size(81);
	set("magic_resist", 45);
	set_level(14);
	break;
    case 9 :
	set("short", "Very old Shadowdrake");
	set("damage", ({ 11,25 }) );
	set("breathrandom", 40);
	set("breathbonus", 12);
	set("armor_class", -4);
	set_size(86);
	set("magic_resist", 50);
	set_level(15);
	break;
    case 10 :
	set("short", "Venerable Shadowdrake");
	set("damage", ({ 12,26 }) );
	set("breathrandom", 44);
	set("breathbonus", 13);
	set("armor_class", -5);
	set_size(90);
	set("magic_resist", 55);
	set_level(16);
	break;
    case 11 :
	set("short", "Wyrm Shadowdrake");
	set("damage", ({ 13,27 }) );
	set("breathrandom", 48);
	set("breathbonus", 14);
	set("armor_class", -6);
	set_size(94);
	set("magic_resist", 60);
	set_level(17);
	break;
    case 12 :
	set("short", "Great Wyrm Shadowdrake");
	set("damage", ({ 14,28 }) );
	set("breathrandom", 52);
	set("breathbonus", 15);
	set("armor_class", -7);
	set_size(100);
	set("magic_resist", 70);
	set_level(18);
	break;
    case 13 :
	set("short", "Giant Shadowdrake");
	set("damage", ({ 20,34 }) );
	set("breathrandom", 60);
	set("breathbonus", 17);
	set("armor_class", -11);
	set_size(150);
	set("magic_resist", 80);
	set_level(23);
	break;
    case 14 :
	set("short", "Huge Shadowdrake");
	set("damage", ({ 24,38 }) );
	set("breathrandom", 68);
	set("breathbonus", 19);
	set("armor_class", -15);
	set_size(200);
	set("magic_resist", 90);
	set_level(28);
	break;
    case 15 :
	set("short", "Incredibly large Shadowdrake");
	set("damage", ({ 28,42 }) );
	set("breathrandom", 72);
	set("breathbonus", 21);
	set("armor_class", -19);
	set_size(275);
	set("magic_resist", 100);
	set_level(33);
	break;
    case 15 :
	set("short", "Ancient Shadowdrake");
	set("damage", ({ 32,50 }) );
	set("breathrandom", 80);
	set("breathbonus", 23);
	set("armor_class", -23);
	set_size(350);
	set("magic_resist", 110);
	set_level(38);
	break;
    case 15 :
	set("short", "The Mother of all Shadowdrake's");
	set("damage", ({ 36,55 }) );
	set("breathrandom", 88);
	set("breathbonus", 25);
	set("armor_class", -27);
	set_size(450);
	set("magic_resist", 120);
	set_level(43);
	break;
    }
    return 1;
}

/* EOF */