/*
** Creator: Cyanide (02 Jul 98)
** The room that give you con points back, at outrageous cost.
*/

// The cost it takes to increase you con, per point.
#define XP_COST 50000
#define GOLD_COST 25000

#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(ROOT_UID);
    set("light", 1);
    set("long", wrap("You are at the top of a great, stepped "+
	"pyramid. Before you stands a great roaring column of "+
	"flame. As the incredible heat washes over you, you "+
	"sense that to \"kneel\" is to request the favor of this "+
	"oracle of unknown divinity.") );
    set("short", "The Top of a Pyramid");
    set("exits", ([
      "down" : "/d/Outer/Mountcelestia/Area1/pyr_base.c"
    ]) );
    set("item_desc", ([
      "column" : "It radiates intense smokeless heat.\n",
    ]) );
    set("smell", "You smell powerful, raw divinity.\n");
    set("listen", "You hear nothing but the roaring of the flames.\n");
}

void init() {
    add_action("kneel", "kneel");
}

int kneel() {
    int max_con, con;
    string race;

    race = TP->query("race");
    con = TP->query("base_stat/constitution");

    max_con = (NEWUSER_D->query_race_maxes(race))[2];
    max_con += (NEWUSER_D->query_race_adj(race))[2];

    if (TP->query_level() < 5) {
	write(wrap("You are not yet powerful enough to "+
	    "receive this boon. Return when you have reached the "+
	    "fifth level of experience."));
	return 1;
    }

    write("You kneel before the pillar of flame.\n\n");
    say(TPN+" kneels before the pillar of flame.\n");

    write(wrap("As you kneel, you come to understand that as a "+
	race+", your physical constitution may never exceed "+
	max_con+"."));

    if (con >= max_con) {
	write(wrap("\nYou sense you have met that limit, and "+
	    "may grow no healthier at this point."));
	return 1;
    }

    write(wrap("You come to understand that in order to be "+
	"granted the boon of health, you must willingly sacrifice "+
	(++con * XP_COST)+" experience, and "+(con * GOLD_COST)
	+" gold."));
    write("\nWill you make this sacrifice? (Y/N) >");

    return input_to("sacrifice", TP, con);
}

int sacrifice (string str, object player, int con) { 
    int xp_cost, gp_cost, hp;

    if (lower_case(str[0..0])!="y") {
	write("You decline to sacrifice.\n");
	return 1;
    }

    xp_cost = con * XP_COST;
    gp_cost = con * GOLD_COST;
    hp = (int)PROPERTY_D->query_con_hp_bonus(player);

    if ((int)player->query("experience") < xp_cost) {
	write(wrap("You do not have enough experience to make "+
	    "a worthy sacrifice.\nA voice booms, \"Leave this place "+
	    "in shame.\""));
	return 1;
    }

    if (!player->debit(gp_cost)) {
	write(wrap("You do not have enough wealth to make "+
	    "a worthy sacrifice.\nA voice booms, \"Leave this place "+
	    "in shame.\""));
	return 1;
    }

    player->add("experience", (-1 * xp_cost));

    write(wrap("Even before you fully contemplate your intent, "+ 
	"the flames rush forward and engulf you!\n\nThrough the "+
	"haze of searing pain, you understand that you are being "+
	"remade in a stronger form."));
    say(TPN+" is suddenly engulfed by the flames!\n");

    player->add("base_stat/constitution", 1);
    player->add("stat/constitution", 1);

    hp = (int)PROPERTY_D->query_con_hp_bonus(player) - hp;
    player->add("max_hp", player->query_level() * hp);

    write("\nYou emerge purified.\n\n");
    say(player->query("cap_name")+" stands, seemingly unscathed.\n");

    player->force_me("save");

    return 1;
}


/* EOF */
