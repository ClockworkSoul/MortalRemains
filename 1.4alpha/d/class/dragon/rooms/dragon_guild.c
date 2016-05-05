// File:    Dragon_guild.c
// Purpose: The guild of DRAGONS
//      Their very own class and group.
//      Not bad, eh?
// Credit/Blame:
//      27 Nov 98  Cyanide created the file 

#include <daemons.h>
#include <move.h>

#define DRAGON "/d/class/dragon/"
#define DRAGON_SP ({ 0,8,13,25,35,60,75,105,130,180,210,260,340,390,\
  480,530,655,730,765,940,1040 })
#define HP_ROLL random(10) + random(10) + random(10) + 3

inherit GUILD;

int query_bonus_sp (object);

void create() {
    ::create();
    seteuid(getuid());
    set("short", "The Lair of the Dragon");
    set("long", wrap("Needs a descrip."));
    set("class", "dragon");
    set("group", "dragon");
    set("light", 1);
    set("min_stats", ([
      "strength" : 15,
      "intelligence" : 15,
    ]) );
}

string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("dragon");
    if (lvl>30) lvl = 30;
    str = ({
    "$N the Egg ($A)",
    "$N the Newborn Hatchling ($A)",
    "$N the Hatchling ($A)",
    "$N the Beginning Apprentice ($A)",
    "$N the Apprentice ($A)",
    "$N the Advancing Apprentice ($A)",
    "$N the Skilled Apprentice ($A)",
    "$N the Senior Apprentice ($A)",
    "$N the Graduate Mage ($A)",
    "$N the Beginning Mage ($A)",
    "$N the Advancing Mage ($A)",
    "$N the Mage ($A)",
    "$N the Academician ($A)",
    "$N the Learned Mage ($A)",
    "$N the Skilled Mage ($A)",
    "$N the Adepta Minor ($A)",
    "$N the Adept Mage ($A)",
    "$N the Adepta Major ($A)",
    "$N the Archmagess ($A)",
    "$N the Mistress of the First Circle ($A)",
    "$N the Mistress of the Second Circle ($A)",
    "$N the Mistress of the Third Circle ($A)",
    "$N the Mistress of the Fourth Circle ($A)",
    "$N the Mistress of the Fifth Circle ($A)",
    "$N the Mistress of the Sixth Circle ($A)",
    "$N the Mistress of the Seventh Circle ($A)",
    "$N the Mistress of the Eighth Circle ($A)",
    "$N the Mistress of the Ninth Circle ($A)",
    "$N the Arcanamach ($A)",
    "$N the Mistress of Sorcery ($A)",
    "$N the Great Wyrm ($A)",
    "$N the Ancient Great Wyrm ($A)" 
  })[lvl];

    return str;
}                


int join() {
    int sp, brains, i;
    object pendant;
    string str;

    if (TP->query_level()) {
	write("You are already pursuing another career.\n"+
	  "You may not become a dragon.\n");
	return 0;
    }

    if (TP->query("base_stat/intelligence") < 9) {
	write("You are not intelligent enough to be a dragon!\n");
	return 0;
    }

    /*
	    if (TP->query("base_stat/constitution") < 15) {
		    write("Your frail form cannot withstand the transformation!\n");
		    return 0;
	    }
    */

    pendant = clone_object(DRAGON+"obj/dragonob.c");
    if (!pendant) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }

    pendant->move(this_player());

    str = wrap("Suddenly, a great force tears through your body! "+
      "You are filled with agony you have never before known as "+
      "you feel yourself changing. You watch as your hands twist "+
      "into claws, and you skin transforms into a scaled hide. "+
      "Then, as soon as it began, it is over, and you are "+
      "changed.");

    write(str);

    sp = DRAGON_SP[1];
    sp += query_bonus_sp(TP);
    TP->set("mage_spells", ({ "detect_magic" }) );
    set_sp(TP, sp);

    TP->set_skill("Unarmed", 1, "strength");

    brains = this_player()->query("stat/intelligence");
    switch (brains) {
    case 0..8 : brains = 1; break;
    case 9..11 : brains = 2; break;
    case 12..13 : brains = 3; break;
    case 14..15 : brains = 4; break;
    default : brains-=11; break;
    }

    // We reset size to that of a dragon.
    // Baby dragons always have a size of 6.
    TP->set("race", "dragon");
    TP->add("languages", ([ "dragon" : 100 ]) );
    TP->set_size(6);

    TP->set("weapon_name", "claws");
    TP->set("damage_type", "slashing");
    TP->set("damage", ({ 1, 6 }) );
    TP->set_verbs( ({ "claw", "slash" }) );

    // How do you do this stat thingie?
    i = TP->query("base_stat/strength");
    i+=2;
    if (i > 20) i = 20;
    GUILD_D->set_stat(TP, "strength", i);
    return 1;

    // Here, we do skills stuff.
    TP->set("nwp_free", (2 + brains)); 
    TP->set("wp_free", 2);
    write("Type \"learn\" to choose your new spell.\n");   
}


int advance() {
    int level, hp, max;

    level = TP->query_level("dragon");
    write("You advance to level "+level+".\n");

    if(level%4==0) TP->add("nwp_free", 1);
    if(level%4==0) TP->add("wp_free", 1);

    hp = query_bonus_sp(TP);
    if (level > 20) {
	hp += ((21 - level) * 100);
	level = 20;
    }
    hp += DRAGON_SP[level];

    // Here, we calc the new base armor class.
    // AC maxes out at
    max = (level/2);
    if (max > 30) max = 30;
    TP->set("base_ac", 10 - (30/2) );

    // Now we set barehanded (clawed?) damage
    if (level > 6)
	TP->set("damage", ({ level/5, level }) );

    // Weapon resistance at very, very high levels.
    TP->set("weap_resist", level/10);

    // And the ability to hit magical creatures!
    TP->set("enchantment", (level/7) + 1);

    // Dragons get half of what mages do.
    set_sp (TP, (hp/2));

    hp = HP_ROLL;
    add_hp(TP, hp);

    // Size is equal to lvl * 2, +4. Max lvl is 30 for size
    // purposes.
    // Reusing hp.  Sorry!
    hp = level;
    if (hp>30) hp = 30;
    hp = (hp*2) + 4;

    GUILD_D->set_player_size(TP, hp);

    write("Type \"learn\" to choose your new spell.\n");
    return 1;
}

int query_bonus_sp (object ob) {
    int brains = ob->query("base_stat/intelligence"), sp;

    switch(brains) {
    case  0..11 : sp = 2; break;
    case 12..13 : sp = 3; break;
    case 14..15 : sp = 4; break;
    case 16 : sp = 5; break;
    case 17 : sp = 6; break;
    case 18 : sp = 7; break;
    case 19 : sp = 8; break;
    default : sp = 9;
    }

    return sp;
}


int learn () {
    "/d/class/wizard/std/daemons/learn.c"->begin_learn(TP); 
    return 1;
}


void register() {
    object pendant;

    pendant = present("dragon pendant", TP);
    if (!pendant && TP->query_level("dragon")) {
	pendant = clone_object(DRAGON+"obj/dragonob.c");
	pendant->move(TP);
    }

    return;
}


/* EOF */
