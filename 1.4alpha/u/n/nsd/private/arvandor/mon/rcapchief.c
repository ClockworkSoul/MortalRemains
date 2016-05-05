/*
** File: rcapchief.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <mudlib.h>
#include "arv.h"
inherit MONSTER ;

object weapon;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    enable_commands() ;
    set("author", "nsd");
    set ("short", "a Red Cap Chief");
    set ("long", wrap(
	"The Goblin Chief. He's dressed in rags and wears a\n"+
	"red cap (from which their comunity name come from).\n"+
	"The red caps use to tint their caps with human blood.\n"+
	"Beware of them!!!\n"));
    set ("id", ({ "chief", "red cap", "goblin" }) );
    set_size(4);
    set_name ("red cap");
    set ("gender", "male");
    set ("race", "goblin");
    enable_commands() ;
    set_living_name("red cap");
    set ("natt", 2);
    set("chat_chance", 50);
    set("chat_output", ({
    }) );
    set("armor_class", 10);
    set("base_ac", 5);
    set_skill("Axes", 5, "Strength");
    set_skill("Mental Resistance", 4, "Strength");
    set("attack_strength", 15);
    set("CLASS", "warrior");
    set("stat/intelligence", 6);
    set("stat/strength", 15);
    set("stat/constitution", 10);
    set("stat/dexterity", 15);
    set("stat/charisma", 9);
    set("weapon_name", "fists");
    set_verbs( ({ "attack", "swing at", "peer at", "hit" }) );
    set("patrol", ({ "north", "south", "east", "west", }) );
    weapon = clone_object(ARV_WEAP+"gobaxe.c");
    weapon->move(this_object());
    set_level(16);
}
void init(){
    ::init();
    command("wield axe");
}

/* EOF */
