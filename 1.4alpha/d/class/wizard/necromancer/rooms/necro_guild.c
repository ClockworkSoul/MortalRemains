/*
** Necromancers's Guild
** Begun by Cyanide, 10 Aug 97
** 29 May 98	Cyanide finally made the necros's guildhall!
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#define NECROS "/d/class/wizard/necromancer/" 
#define MAGE_SP ({ 0,8,13,25,35,60,75,105,130,180,210,260,340,390,\
  480,530,655,730,765,940,1040 })

#define ALLOWED_RACES ({ "drow", "human" })   

int query_bonus_sp (object);

#include <config.h>
#include <daemons.h>
#include <mudlib.h>
#include <c_wizards.h>

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "In the crypt") ;
    set ("long", @End_Guild
You are in an ancient, hidden crypt that serves as the
guildhall of the Necromancers. An ancient, black-robed 
skeleton sits in a cobweb-covered wooden throne, moldering 
silently.
There is a pulsating black portal here.

You can do the following here: join, dual, advance, or register.
End_Guild
    );
    set("light", 1);
    set("exits", ([
    ]) );
    set("class", "necromancer");
    set("group", "wizard");
    set("experience", WIZARD_XP);
}

void init() {
    ::init();
    add_action("learn", "learn");
    add_action("enter", "enter");
}

string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("necromancer");
    if (lvl>30) lvl = 30;
    if ((string)ob->query("gender")=="female") {
	str = ({
	"$N the Peasant ($A)",
	"$N the Necrophile ($A)",			// 1
	"$N the Grave Digger ($A)",
	"$N the Student Anatomist ($A)",
	"$N the Anatomist ($A)",
	"$N the Necrologist ($A)",		// 5
	"$N the Spiritualist ($A)",
	"$N the Channeler of Spirits ($A)",
	"$N the Initiate of the Cabal ($A)",
	"$N the Student of Necromancy ($A)",
	"$N the Lesser Necromancer ($A)",	// 10
	"$N the Necromancer ($A)",
	"$N the Animator ($A)",
	"$N the Scabrous One ($A)",
	"$N the Bringer of Plagues ($A)",
	"$N the Poisoner of the Cabal ($A)",	// 15
	"$N the Philosopher of the Cabal ($A)",
	"$N the Visioness of the Cabal ($A)",
	"$N the Screamer in the Darkness ($A)",
	"$N the Wanderer in the Darkness ($A)",
	"$N the Traveller in the Darkness ($A)",	// 20
	"$N the Sorcereress of the Cabal ($A)",
	"$N the Lady of the Cabal ($A)",
	"$N the Mistress of Decay ($A)",
	"$N the Mistress of Shadows ($A)",
	"$N the Mistress of Ghouls ($A)",	// 25
	"$N the Mistress of Undead ($A)",
	"$N the Arch-necromancer ($A)",
	"$N the Mistress of the Cabal ($A)",
	"$N the Grand Mistress of the Cabal ($A)",
	"$N the Necromancer Queen ($A)",			// 30
	"$N the Eternal Lich ($A)" })[lvl];
    } else {
	str = ({
	"$N the Peasant ($A)",
	"$N the Necrophile ($A)",			// 1
	"$N the Grave Digger ($A)",
	"$N the Student Anatomist ($A)",
	"$N the Anatomist ($A)",
	"$N the Necrologist ($A)",		// 5
	"$N the Spiritualist ($A)",
	"$N the Channeler of Spirits ($A)",
	"$N the Initiate of the Cabal ($A)",
	"$N the Student of Necromancy ($A)",
	"$N the Lesser Necromancer ($A)",	// 10
	"$N the Necromancer ($A)",
	"$N the Animator ($A)",
	"$N the Scabrous One ($A)",
	"$N the Bringer of Plagues ($A)",
	"$N the Poisoner of the Cabal ($A)",	// 15
	"$N the Philosopher of the Cabal ($A)",
	"$N the Visionist of the Cabal ($A)",
	"$N the Screamer in the Darkness ($A)",
	"$N the Wanderer in the Darkness ($A)",
	"$N the Traveller in the Darkness ($A)",	// 20
	"$N the Sorcerer of the Cabal ($A)",
	"$N the Champion of the Cabal ($A)",
	"$N the Master of Decay ($A)",
	"$N the Master of Shadows ($A)",
	"$N the Master of Ghouls ($A)",	// 25
	"$N the Master of Undead ($A)",
	"$N the Arch-necromancer ($A)",
	"$N the Master of the Cabal ($A)",
	"$N the Grand Master of the Cabal ($A)",
	"$N the Necromancer King ($A)",			// 30
	"$N the Eternal Lich ($A)" })[lvl];
    }
    return str;
}                


int join() {
    int sp, brains, i;
    object hourglass;

    if (TP->query("base_stat/intelligence") < 9) {
	write("You are not intelligent enough to be an invoker!\n");
	return 0;
    }

    if (TP->query("base_stat/wisdom") < 16) {
	write("Your frail mind cannot take the rigors"+
	  " of necromancy!\n");
	return 0;
    }

    if (member_array((string)TP->query("race"), 
	ALLOWED_RACES)==-1) {
	write("Your race doesn't have enough necromantic talent.\n");
	return 0;
    }

    if (TP->query_level("wizard")) return 1; 

    write(@Welcome
The robed skeleton stirs... It says to you, "Welcome, Initiate."
The skeleton hands you an hourglass, and says, "Take care of 
this gift, child, and it will serve you well.
Welcome
    );

    hourglass = clone_object(NECROS+"obj/hourglass.c");
    if (!hourglass) {
	write("\nThe lich says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }

    hourglass->move(this_player());
    sp = MAGE_SP[1];
    sp += query_bonus_sp(TP);
    TP->set("opposition_schools", ({ "illusion", "enchantment" }) );
    TP->set("specialization", "necromancy");
    TP->set("mage_spells", ({ "detect_magic", "chill" }) );
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

    level = TP->query_level("necromancer");
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
    object hourglass;

    hourglass = present("hourglass", TP);
    if (!hourglass && TP->query_level("necromancer")) {
	hourglass = clone_object(NECROS+"obj/hourglass.c");
	hourglass->move(TP);
    }

    return;
}


int enter(string str) {
    if (str!="portal") {
	write("Enter what?\n");
	return 1;
    }

    write(wrap("You enter the portal, and space suddenly "+
	"warps sickeningly."));
    say(TPN+" enters the portal and dissapears.\n");
    TP->move_player("/d/Outer/Sigil/coffin.c", "SNEAK");
    say(TPN+" suddenly appears, lying beside you!\n");
    return 1;
}
