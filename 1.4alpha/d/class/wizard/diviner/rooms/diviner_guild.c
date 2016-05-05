/*
** Necromancers's Guild
** Begun by Cyanide, 10 Aug 97
** 29 May 98	Cyanide finally made the necros's guildhall!
** 08 Nov 98    Now it's the diviner's guildhall!
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#define DIVINERS "/d/class/wizard/diviner/" 
#define MAGE_SP ({ 0,8,13,25,35,60,75,105,130,180,210,260,340,390,\
  480,530,655,730,765,940,1040 })

#define ALLOWED_RACES ({ "human", "elf", "half-elf", "drow" })   

int query_bonus_sp (object);

#include <config.h>
#include <daemons.h>
#include <mudlib.h>
#include <c_wizards.h>

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "Among the Stacks") ;
    set ("long", "@@query_long");
    set("light", 1);
    set("exits", ([
      "west" : "/d/Outer/Sigil/partedviel.c",
    ]) );
    set("class", "diviner");
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

    lvl = ob->query_level("diviner");
    if (lvl>30) lvl = 30;
    if ((string)ob->query("gender")=="female") {
	str = ({
	"$n the Stupid ($A)",                   // 0
	"$N the Observant ($A)",                // 1
	"$N the Bone Reader ($A)",
	"$N the Card Reader ($A)",
	"$N the Fortune Teller ($A)",
	"$N the Well Read ($A)",                // 5
	"$N the Knowledgable ($A)",
	"$N the Clear Thinking ($A)",
	"$N the Apprentice Diviner ($A)",
	"$N the Student of Divination ($A)",
	"$N the Beginning Diviner ($A)",        // 10
	"$N the Studious Apprentice Diviner ($A)",
	"$N the Lesser Diviner ($A)",
	"$N the Diviner ($A)",
	"$N the the Scrying ($A)",
	"$N the Mindreader ($A)",               // 15
	"$N the Reader of Souls ($A)",          
	"$N the Seer ($A)",
	"$N the Lorekeeper ($A)",
	"$N the Arch-diviner ($A)",
	"$N the Philosopher ($A)",              // 20
	"$N the Bringer of Knowledge ($A)",     
	"$N the Wise Woman ($A)",
	"$N the Prophet ($A)",
	"$N the Mistress of Knowledge ($A)",
	"$N the Ancient Diviner ($A)",          // 25
	"$N the Consult to Kings ($A)",         
	"$N the Diviner Queen ($A)",
	"$N the All Seeing ($A)",
	"$N the All Knowing ($A)",
	"$N the Omniscient ($A)",               // 30
      })[lvl];
    } else {
	str = ({
	"$n the Stupid ($A)",                   // 0
	"$N the Observant ($A)",                // 1
	"$N the Bone Reader ($A)",
	"$N the Card Reader ($A)",
	"$N the Fortune Teller ($A)",
	"$N the Well Read ($A)",                // 5
	"$N the Knowledgable ($A)",
	"$N the Clear Thinking ($A)",
	"$N the Apprentice Diviner ($A)",
	"$N the Student of Divination ($A)",
	"$N the Beginning Diviner ($A)",        // 10
	"$N the Studious Apprentice Diviner ($A)",
	"$N the Lesser Diviner ($A)",
	"$N the Diviner ($A)",
	"$N the the Scrying ($A)",
	"$N the Mindreader ($A)",               // 15
	"$N the Reader of Souls ($A)",          
	"$N the Seer ($A)",
	"$N the Lorekeeper ($A)",
	"$N the Arch-diviner ($A)",
	"$N the Philosopher ($A)",              // 20
	"$N the Bringer of Knowledge ($A)",     
	"$N the Wise Man ($A)",
	"$N the Prophet ($A)",
	"$N the Master of Knowledge ($A)",
	"$N the Ancient Diviner ($A)",          // 25
	"$N the Consult to Kings ($A)",         
	"$N the Diviner King ($A)",
	"$N the All Seeing ($A)",
	"$N the All Knowing ($A)",
	"$N the Omniscient ($A)",               // 30
      })[lvl];
    }
    return str;
}                


int join() {
    int sp, brains, i;
    object specs;

    if (TP->query("base_stat/intelligence") < 9) {
	write("You are not intelligent enough to be a diviner!\n");
	return 0;
    }

    if (TP->query("base_stat/wisdom") < 15) {
	write("You lack the common sense to become a diviner.\n");
	return 0;
    }

    if (member_array((string)TP->query("race"), 
	ALLOWED_RACES)==-1) {
	write("Your race doesn't have enough divinatory talent.\n");
	return 0;
    }

    if (TP->query_level("wizard")) return 1; 

    write(wrap("The old grins a toothless, but good-hearted smile."+
	" \"Welcome among us, he says, and hands you a pair of "+
	"spectacles. \"Here\", he says. \"You'll need these after "+
	"reading in the candlelight for a while.\" With that, he "+
	"turns back to his studies."));

    specs = clone_object(DIVINERS+"obj/specs.c");
    if (!specs) {
	write("\nThe old man says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }

    specs->move(this_player());
    sp = MAGE_SP[1];
    sp += query_bonus_sp(TP);
    TP->set("opposition_schools", ({ "conjuration" }) );
    TP->set("specialization", "divination");
    TP->set("mage_spells", ({ "detect_magic", "missile" }) );
    set_sp(TP, sp);

    if (!TP->query_skill("One Weapon Style"))
	TP->set_skill("One Weapon Style", 1);

    if (!TP->query_skill("Two Handed Style"))
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

    level = TP->query_level("diviner");
    write("You advance to level "+level+".\n");

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%6==0) TP->add("wp_free", 1);

    hp = query_bonus_sp(TP);
    if (level > 20) {
	hp += ((level - 20) * 100);
	level = 20;
    }

    hp += MAGE_SP[level];
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
    object specs;

    specs = present("diviner specs", TP);
    if (!specs && TP->query_level("diviner")) {
	specs = clone_object(DIVINERS+"obj/specs.c");
	specs->move(TP);
    }

    return;
}

string query_long() {
    string str = "Sitting here, among the dustiest and oldest "+
    "books, are a group of several man, all aged and bespectacled, "+
    "reading thick tomes by candlelight. ";

    if (TP->query_level("diviner")) {
	str += "One man looks at you and says, \"Welcome fellow diviner. "+
	"Please feel free to 'advance' or 'learn' while you are here.\"";
    } else {
	str += "One man looks at you and says, \"Welcome stranger. If you "+
	"meet our criteria, you may 'join' our guild, or 'dual', "+
	"whichever is appropriate.\"";
    }

    return wrap(str);
}
/* EOF */
