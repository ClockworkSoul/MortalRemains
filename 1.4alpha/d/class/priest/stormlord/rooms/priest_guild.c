/*
** Priests of tempus (used cy's mages guild as base.) -ilz
*/

#include <daemons.h>
#include <config.h>
#include <mudlib.h>
#include <c_priests.h>

inherit "/d/class/priest/std/daemons/learnspell.c";

int query_bonus_tp (object);

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "The Temple of Talos") ;
    set("long", @ENDLONG
This temple was once a small Baptist church, but it was all but destroyed
in a fire several years ago, and now hosts the worshipping of an ancient,
nearly forgotten deity.

You can do the following here: join, dual, advance, or register.
ENDLONG
    );
    set("light", 1) ;
    set("class", "stormlord");
    set("group", "priest");
    set("experience", PRIEST_XP);
    set ("exits", ([
      "south" : "/d/class/priest/stormlord/rooms/boardrm",
      "north" : "/d/Prime/Central/room/road2_0.c",
    ]) );
}

string titles (object ob) {
    string str, diety;
    int lvl;

    diety = ("Talos");
    lvl = ob->query_level("priest");
    if (lvl>30) lvl = 30;

    str = ({
    "$N the blah of "+diety+" ($A)",
    "$N the Worshipper of "+diety+" ($A)",
    "$N the Worshipper of "+diety+" ($A)",
    "$N the Initiate Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",
    "$N the Stormlord of "+diety+" ($A)",  
  })[lvl];

    return str;
}                

int get_tp(int i) {
    switch (i) {
    case 0..20 : i = ((18 * (i*i))/10) + 20; break;
    default: i = 740 + ((i-20)*75); break;
    }

    return i;
}

int join() {
    object robes;
    int tp, brains;
    if (TP->query("base_stat/wisdom") < 14) {
	write("You are not wise enough to be a member!\n");
	return 0;
    }

    if (TP->query("base_stat/strength") < 13) {
	write("You are not strong enough for us!\n");
	return 0;
    }
    if (!(TP->query_alignment() == "chaotic evil")){
	write("You are not chaotic evil enough for us!\n");
	return 0;
    }

    write("A voice says, \"Welcome little one...\"\n");
    write("The air shimmers, and some robes appear in your hands.\n");
    write("A voice says, \"Take care of this gift, child, and it"+
      " will serve you well.\"\n");

    tp = get_tp(1);
    tp += query_bonus_tp(TP);
    set_tp(TP, tp);

    TP->set("resist_type", ([ "electricity" : 0 ]) );
    TP->set("base_resist",([ "electricity" : 0 ]) );

    TP->add("priest_spells", ({ "detect_magic" }));
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

    TP->set("deity", "talos");
    robes = clone_object(TALOS+"obj/talosrobes.c");
    if (!robes) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
    } else {
	robes->move(this_player());
    }

    return 1;
}

int advance() {
    int level, hp, max;
    string spell;

    if (TP->query("deity") != "talos"){
	write("Go advance in your own guild!\n");
	return 0;
    }

    level = TP->query_level("stormlord");

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%4==0) TP->add("wp_free", 1);

    hp = get_tp( level );
    hp += query_bonus_tp(TP);
    set_tp (TP, hp);

    hp = PRIEST_HP_ROLL;
    add_hp(TP, hp);

    level = (TP->query_level("priest"));
    write("You advance to level "+level+".\n");
    if (level == 7)
	spell = "bolt";
    else
	spell = learn_spell(TP);

    write(wrap("Talos grants you, his loyal Destroyer, the power of the "+spell+" spell."));
    TP->add("priest_spells", ({ spell }) );

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

/* EOF */
