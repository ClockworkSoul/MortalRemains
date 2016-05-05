/*
** Mage's Guild
** Begun by Cyanide, 10 Aug 97
*/

#define MAGE_SP ({ 0,4,9,15,25,40,55,70,95,120,150,200,250,300,\
  350,400,475,550,625,700,800,900,1000,1100,1200,1300,1400,1500,1600,\
  1700,1800,1900,2000 })

#define ALLOWED_RACES ({ "drow", "elf", "githzerai", "half-elf", \
    "human" })   

int query_bonus_sp (object);

#include <daemons.h>
#include <mudlib.h>
#include <c_wizards.h>
#include "guildhall.h"

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "Inside the Main Library");
    set ("long", wrap("You stand with the hallowed halls of "+
	"Magicka University. You feel almost as though you stand "+
	"upon the very pulse of magic. Professors in embroidered "+
	"robes walk the halls, their familars scrambling to keep "+
	"up. Glowing spheres of light float serenely near the "+
	"ceiling, filling the halls with a distinct golden light. "+
	"There is much to be learned here.\n\n"+
	"You can do the following here: join, dual, advance, or "+
	"register.\nYou may also 'spellcraft' any known spell in "+
	"this room.") );
    set("light", 1);
    set("exits", ([
      "west" : RM_MAGES+"m_lobby",
    ]) );
    set("class", "mage");
    set("group", "wizard");
    set("experience", WIZARD_XP);
}

void init() {
    ::init();
    add_action("learn", "learn");
}

string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("mage");
    if (lvl > 31) lvl = 31;
    if ((string)ob->query("gender")=="female") {
	str = ({
	"$N the Peasant ($A)",
	"$N the Scribe ($A)",
	"$N the New Apprentice ($A)",
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
	"$N the Sorceress Queen ($A)",
	"$N the Arcaness ($A)" 
      })[lvl];
    } else {
	str = ({
	"$N the Peasant ($A)",
	"$N the Scribe ($A)",
	"$N the New Apprentice ($A)",
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
	"$N the Adeptus Minor ($A)",
	"$N the Adept Mage ($A)",
	"$N the Adeptus Major ($A)",
	"$N the Archmage ($A)",
	"$N the Master of the First Circle ($A)",
	"$N the Master of the Second Circle ($A)",
	"$N the Master of the Third Circle ($A)",
	"$N the Master of the Fourth Circle ($A)",
	"$N the Master of the Fifth Circle ($A)",
	"$N the Master of the Sixth Circle ($A)",
	"$N the Master of the Seventh Circle ($A)",
	"$N the Master of the Eighth Circle ($A)",
	"$N the Master of the Ninth Circle ($A)",
	"$N the Arcanamach ($A)",
	"$N the Master of Sorcery ($A)",
	"$N the Sorcerer King ($A)",
	"$N the Arcanist ($A)" })[lvl];
    }
    return str;
}                

int get_sp(int i) {
    switch (i) {
    case 0..20 : i = (2 * (i*i)) + 10; break;
    default: i = 810 + ((i-20)*80); break;
    }

    return i;
}

int join() {
    int sp, brains, i;
    object book;

    if (TP->query("base_stat/intelligence") < 9) {
	write("You are not intelligent enough to be a wizard!\n");
	return 0;
    }

    if (member_array((string)TP->query("race"), 
	ALLOWED_RACES)==-1) {
	write("Your race doesn't have enough magical talent.\n");
	return 0;
    }

    if (TP->query_level("wizard")) return 1; 

    write("A voice says, \"Welcome child...\"\n");
    write("The air shimmers, and a book appears in your hands.\n");
    write("A voice says, \"Take care of this gift, child, and it"+
      " will serve you well.\"\n");

    book = clone_object(MAGE+"obj/book.c");
    if (!book) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }

    book->move(this_player());
    sp = get_sp(1);
    sp += query_bonus_sp(TP);
    TP->set("mage_spells", ({ "detect_magic", "missile" }) );
    set_sp(TP, sp);

    TP->set_skill("One Weapon Style", 1);
    TP->set_skill("Two Handed Style", 1);

    brains = this_player()->query("stat/intelligence");
    switch (brains) {
    case 0..8 : brains = 1; break;
    case 9..11 : brains = 2; break;
    case 12..13 : brains = 3; break;
    case 14..15 : brains = 4; break;
    default : brains-=11; break;
    }

    TP->set("nwp_free", (4 + brains)); 
    TP->set("wp_free", 1);
    write("Type \"learn\" to choose your new spell.\n");   
    return 1;
}

int advance() {
    int level, hp, max;

    level = TP->query_level("mage");
    write("You advance to level "+level+".\n");

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%6==0) TP->add("wp_free", 1);

    //TP->add("mage_spells", SPELL_LIST[level - 1]);

    hp = query_bonus_sp(TP);
    hp += get_sp(level);
    set_sp (TP, hp);

    hp = WIZ_HP_ROLL;
    add_hp(TP, hp);

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
    object book;


    book = present("spell book", TP);
    if (!book && TP->query_level("mage")) {
	book = clone_object(MAGE+"obj/book.c");
	book->move(TP);
    }

    return;
}

/* EOF */
