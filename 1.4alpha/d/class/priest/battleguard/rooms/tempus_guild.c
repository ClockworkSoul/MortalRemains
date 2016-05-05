/*
**Priests of tempus (used cy's mages guild as base.) -ilz
*/

#define FIND find_player("ilzarion")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

// This is a temporary array of priestTP's until I feel like making
// the real priest TP list...
#define PRIEST_TP ({ 0,4,8,15,25,40,55,70,90,125,160,200,240,290,\
  340,400,460,530,600,675,750,825,900,975,1050,1125,1200,1275,1350,\
  1425,1500 })

#include <daemons.h>
#include <mudlib.h>
int query_bonus_tp (object);

inherit GUILD;

inherit "/d/class/priest/std/daemons/learnspell.c";

void create() {
    ::create();
    seteuid(getuid());
    set("short", "The Guild of Tempus");
    set("long", "In this great hall of the brotherhood of battle, \n"+
      "You may select <weapon> for your chosen weapon.\n"+
      "Or Join us and Advance as you see fit.\n");
    set("light", 1);
    set("class", "battleguard");
    set("group", "priest");
    set("experience", PRIEST_XP);
    set ("exits", ([ "sigil" : "/d/Outer/Sigil/clericguild.c" ]) );
}

void init() {
    add_action("weaponchoice", "select");
    ::init();
}

string titles (object ob) {
    string str, diety;
    int lvl;

    diety = ("Tempus");
    lvl = ob->query_level("priest");
    str = ({
    "$N the blah of "+diety+" ($A)",
    "$N the Worshiper of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
    "$N the Battleguard of "+diety+" ($A)",
  })[lvl];

    return str;
}                

int weaponchoice(string weap){
    if (!member_guild(TP)) {
	write("You're not even a member of this class!\n");
	return 1;
    }   

    if (TP->query("weaponchosen")){
	write("You already chose a weapon!\n");
	return 1;
    } 

    switch (weap){
    case "long blades" : weap = "Long Blades";break;
    case "Long Blades" : weap = "Long Blades";break;
    case "short blades" : weap = "Short Blades";break;
    case "Short Blades" : weap = "Short Blades";break;
    case "axes" : weap = "Axes";break;
    case "Axes" : weap = "Axes";break;
    case "clubbing weapons" : weap = "Clubbing Weapons";break;
    case "Clubbing Weapons" : weap = "Clubbing Weapons";break;
    case "polearms" : weap = "Polearms";break;
    case "Polearms" : weap = "Polearms";break;
    case "staves" : weap = "Staves";break;
    case "Staves" : weap = "Staves";break;
    case "whips" : weap = "Whips";break;
    case "Whips" : weap = "Whips";break;
    default : weap = "fail";
    }
    if (weap == "fail"){
	write("You may pick from the folloowing:\n");
	write("Long Blades, Short Blades, Axes, Polearms\n");
	write("Clubbing Weapons, Staves, Whips.\n");
	return 1;
    }
    if (TP->query_skill(weap) > 2){
	write("You are already a master of that weapon type.\n");
	return 1;
    }
    TP->set_skill(weap, 3);
    write ("You have chosen "+weap+" as your weapon of choice.\n");  
    TP->set("weaponchosen", 1);
    return 1;
}


int join() {
    object gauntlets;
    int tp, brains;
    if (TP->query("base_stat/wisdom") < 12) {
	write("You are not wise enough to be a member!\n");
	return 0;
    }
    if (TP->query("base_stat/strength") < 14) {
	write("You are not strong enough for us!\n");
	return 0;
    }

    if ((!(TP->query_alignment() == "chaotic neutral")) &&
      (!(TP->query_alignment() == "chaotic good")) &&
      (!(TP->query_alignment() == "chaotic evil")) ) {
	write("You are not chaotic enough for us!\n");
	return 0;
    }

    write("A voice says, \"Welcome child...\"\n");
    write("The air shimmers, and a pair of gauntlets appear in your hands.\n");
    write("A voice says, \"Take care of this gift, child, and it"+
      " will serve you well.\"\n");

    tp = PRIEST_TP[1];
    tp += query_bonus_tp(TP);
    set_tp(TP, tp);
    TP->add("priest_spells", ({ "battlefate" }));
    TP->set_skill("One Weapon Style", 1);
    TP->set_skill("Two Handed Style", 1);
    TP->set_skill("Shield Style", 1);
    brains = this_player()->query("stat/intelligence");
    switch (brains) {
    case 0..8 : brains = 1; break;
    case 9..11 : brains = 2; break;
    case 12..13 : brains = 3; break;
    case 14..15 : brains = 4; break;
    default : brains-=11; break;
    }

    TP->set("nwp_free", (4 + brains)); 
    TP->set("wp_free", 2);

    TP->set("deity", "tempus");
    gauntlets = clone_object(TEMPUS+"obj/gauntlets.c");
    if (!gauntlets) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }
    gauntlets->move(this_player());
    return 1;
}

int advance() {
    int level, hp, max;
    string spell;
    if (TP->query("deity") != "tempus"){
	write("Go advance in your own guild!\n");
	return 0;
    }
    level = (TP->query_level("priest"));
    write("You advance to level "+level+".\n");

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%4==0) TP->add("wp_free", 1);

    hp = query_bonus_tp(TP);
    hp += PRIEST_TP[level];
    set_tp (TP, hp);
    spell = learn_spell();
    TP->add("priest_spells", ({ spell }) );
    write ("The great tempus bestows upon you the power of the "+spell+" spell.\n");
    // TP->add("priest_spells", SPELL_LIST[level - 1]);

    hp = PRIEST_HP_ROLL;
    add_hp(TP, hp);
    return 1;
}
int query_bonus_tp (object ob) {
    int brains = ob->query("base_stat/wisdom"), sp;

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
void register() {
    object book;

    DEBUG("Registering "+TPN+"\n");

    book = present("gauntlets", TP);
    if (!book && TP->query_level("priest")) {
	book =  clone_object(TEMPUS+"obj/gauntlets.c");
	book->move(TP);
    }

    return;
}
