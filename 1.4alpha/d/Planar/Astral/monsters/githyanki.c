/*
** File: githyanki.c
** Purpose: Creates a random githyanki type.
** Credits:
**   15Nov97  Cyanide created the file.
*/

#include <mudlib.h>
#include <daemons.h>
#include "../Astral.h"

void set_class (string, int);
string generate_name();
varargs int query_level(string);

int level;
object armor, class_ob, weapon, tmp_ob;
string *classes;
string *spells;
int *SP = ({ 0,4,9,15,25,40,55,70,95,120,150,200,250,300,350 });

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    classes = ({});

    // set("aggressive", 8);   // It attacks all non-githyanki.
    set("race", "githyanki");
    if (!random(10)) set("gender", "female");
    else set("gender", "male");
    set_true_align( (random(2)-1), -1 );  // Any evil.
    set_size(6);
    set("id", ({ "githyanki", "gith" }) );
    set("short", "@@query_short");
    set("author", "cyanide");
    set("long", "@@query_long");
    set_name(generate_name());
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ;
    set_verbs( ({ "swing at" }) );
    set("stat/intelligence", 15+random(5) );
    set("prevent_summon", 1);
    set("lore_type", "demon");
    set("special", 1);
    set("mage_spells", ({}) );
    credit(200+random(200));

    // Cyanide: Let's figure out the thing's level like this:
    switch (random(100)+1) {
    case  1..20 : level = 3; break;
    case 21..30 : level = 4; break;
    case 31..40 : level = 5; break;
    case 41..60 : level = 6; break;
    case 61..80 : level = 7; break;
    case 81..90 : level = 8; break;
    case 91..95 : level = 9; break;
    case 96..98 : level = 10; break;
    default : level = 11; break;
    }

    // Cyanide: And this does the class stuff
    switch (random(100)+1) {
    case 1..20 : set_class ("mage", level); 
	classes = ({ "wizard", "mage" });
	break;
    case 21..75 : set_class ("fighter", level); 
	classes = ({ "fighter", "warrior" });
	set("class", "fighter");
	set("CLASS", "warrior");
	break;
    default : level -= random(3);
	set_class ("fighter", level);
	classes = ({ "fighter", "warrior" });
	set("class", "fighter");    
	set("CLASS", "warrior");   
	set_class ("mage", level);
	classes = ({ "warrior", "fighter", "wizard", "mage" });
	break;
    }
}


// This substitutes for the normal query_level().
// Let's make them act as much like players as possible!

varargs int query_level(string klass) {
    if (!klass) return (int)query("level");

    klass = lower_case(klass);

    if (member_array(klass, classes)!=-1)
	return (int)query("level");
    else
	return 0;
}

void init() {
    string to_cast;
    object *stuff;
    int ii;

    ::init();

    stuff = all_inventory(this_object());
    for (ii=0; ii<sizeof(stuff); ii++) {
	if (stuff[ii]->query("weapon")) {
	    to_cast = (string)(stuff[ii]->query("id")[0]);
	    command("wield "+to_cast);
	}
    }

    to_cast = ({ " hot", " cold" })[random(2)];
    command("cast fireshield"+to_cast);

    if (query_level("mage")) {
	to_cast = spells[ random(sizeof(spells)) ];
	command("cast "+to_cast);
    }
}


void set_class(string klass, int lvl) {
    int x, hp, flag;

    if (klass=="mage") {
	if (query_level("fighter")) {
	    spells = ({ "", "enlarge", "shield", "", "", "haste",
	    "bolt", "fireshield", "", "coldcone", "minorglobe", "" });
	} else {
	    spells = ({ "", "missile", "shield", "colorspray", "", 
	    "fireball", "bolt", "fireshield", "haste", "coldcone", 
	    "minorglobe", "shout" });
	}
    }

    hp = 0;
    flag = 0;
    if (query_level()) flag = 1;

    for (x=0; x<lvl; x++) {
	switch(klass) {
	case "mage" : hp += (random(4)+1) * 3; break;
	case "fighter" : hp += (random(10)+1) * 3; break;
	}
	hp += PROPERTY_D->query_con_hp_bonus(this_object());
    }

    switch(klass) {
    case "mage" :
	set_skill("Short Blades", 1, "strength");
	for (x=1; x<=lvl; x++)
	    if (spells[x]!="") add("mage_spells", ({ spells[x] }) );
	class_ob = clone_object("/d/class/wizard/general/obj/book.c");
	weapon = clone_object(AST_WEAP("dagger.c"));
	break;
    case "fighter" :
	x = 2;
	if (lvl>=6) x++;
	set_skill("Long Blades", x, "strength");
	class_ob = clone_object("/d/class/warrior/general/obj/badge.c");
	weapon = present("dagger", this_object());
	if (weapon) weapon->remove();
	switch(lvl) {
	case 0..5 : 
	    weapon = clone_object(AST_WEAP("Gith_2H.c"));
	    if (!random(2)) weapon->set_bonus(1);
	    break;
	case 6..9 :
	    if (!random(3)) {
		weapon = clone_object(AST_WEAP("Gith_2H.c"));
		weapon->set_bonus(1);
	    } else {
		weapon = clone_object(AST_WEAP("Gith_LS.c"));
		weapon->set_bonus(2);
	    }
	default :
	    if (!random(3)) {
		weapon = clone_object(AST_WEAP("Gith_LS.c"));
		weapon->set_bonus(2);
	    } else {
		weapon = clone_object(AST_WEAP("SilverSword.c"));
	    }
	}
	break;
    }
    if (weapon) weapon->move(this_object());
    class_ob->move(this_object());
    set("special", (lvl/2) );
    set_level(lvl);
    if (flag) {
	add("hit_points", hp);
	add("max_hp", hp);
    } else {
	set("max_hp", hp);
	set("hit_points", hp);
    }

    if (lvl<=14) {
	set("max_sp", SP[lvl]);
	set("spell_points", SP[lvl]);
    }

    spells = query("mage_spells");
}

// This is the function to generate a random Githyanki name.
// Cyanide: I want to do this shit RIGHT!

string generate_name() {
    int syllables = random(2)+2;
    string *Consts = ({ "b","c","ch","ck","d","f","g","hr","h","j","k","l",
    "m","n","p","q","r","s","t","th","v","w","x","y","z" });
    string *Vowels = ({ "a","e","i","o","u","ou","aa","y" });
    string name = "";
    int flag = 0;    // If == 0, then the last letter was a vowel.
    int length, x, y;

    for (x=0; x<syllables; x++) {
	string tmp_str;
	tmp_str = "";
	length = random(3)+1;
	for (y=0; y<length; y++) {
	    if (!flag)
		tmp_str += Consts[ random(sizeof(Consts)) ];
	    else
		tmp_str += Vowels[ random(sizeof(Vowels)) ];
	    flag = !flag;
	}
	name += tmp_str;
	if (x < (syllables-1)) name+="'";
    }

    add("id", ({ name }) );
    return capitalize(name);
}


void special_attack() {

    if (query("cast_delay"))
	return 1;
    else
    if (query_level("mage"))
	command("cast "+spells[random(sizeof(spells))]);

}

string query_short() {
    string name;
    int flag;

    flag = 0;
    if (query_level("mage")) flag++;
    if (query_level("warrior")) flag+=2;

    name = query("cap_name");

    switch(flag) {
    case 0 : name += " the githyanki farmer"; break;
    case 1 : name += " the githyanki wizard"; break;
    case 2 : name += " the githyanki warrior"; break;
    default : name += " the githyanki battle-mage"; break;
    }

    return name;
}
