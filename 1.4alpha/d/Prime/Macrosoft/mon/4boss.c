/*
** Cyclops.c
** Cyanide - 29 Jan 98
*/

#include "macrosoft.h"
#include <mudlib.h>

inherit MONSTER;

void create() {
    object weapon, badge;

    ::create();
    seteuid(getuid());

    // ID stuff.
    set("author", "cyanide");
    set("prevent_summon", 1);
    set("id", ({ "clo", "johnny", "cochran", "johnny cochran" }) );
    set("short", "Johnny Cochran, the Chief Legal Officer");
    set("long", wrap(
	"He appears to you to be nothing more than a normal African-American "+
	"human in an expensive blue suit. "+
	"He seems totally out of place here."
      ) );
    set_name("Johnny Cochran");

    // Body stuff
    set("race", "human");
    set("gender", "male");
    set_size(6);
    set_align("ce");
    set("stat/strength", 12);
    set("stat/constitution", 16);
    set("stat/intelligence", 13);
    set("stat/charisma", 17);

    set("chat_chance", 10);
    set("chat_output", ({
      "Johnny declares: It just doesn't make sense!\n",
      "Johnny declares: If the dress is messed, he must confess!\n",
    }) );
    // Combat stuffs	
    set("damage", ({ 3, 10 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "swing at", "punch" }) );
    set_verbs2( ({ "swings at", "punches" }) );
    set_skill("Unarmed", 4, "strength");
    set_skill("Short Blades", 5, "dexterity");
    set("CLASS", "warrior");

    // Let's give him stuff.
    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(5);
    wear(badge);
    wear(MS_ARMOR("suit"));
    arm(MS_WEAP("lightpen.c"));

    // Always the last!
    set("special", 4);
    set_level(28);
    credit( query("max_hp") );
}


void die() {
    object d = find_object_or_load(MS_D);
    ::die();

    d->reset_resistances();
    return;
}
