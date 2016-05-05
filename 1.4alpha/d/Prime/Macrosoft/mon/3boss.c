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
    set("id", ({ "cfo", "dymar", "cyclops", "giant", "dy-mar" }) ); 
    set("short", "Dy-mar, the Chief Financial Officer");
    set("long", wrap(
	"Through his overpowering body odor, you can barely make out "+
	"his features: A single large, red eye dominates the center "+
	"of his forehead. Despite the stench, he is dressed in an "+
	"expensively tailored black silk suit, and his hair is neatly "+
	"slicked back and parted."
      ) );
    set_name("Dy-mar");

    // Body stuff
    set("race", "cyclops");
    set("gender", "male");
    set_size(20);
    set_align("ce");
    set("stat/strength", 20);
    set("stat/constitution", 16);
    set("stat/intelligence", random(6)+5);

    // Combat stuffs	
    set("damage", ({ 6, 36 }) ) ;
    set("weapon_name", "fists") ;
    set_verbs( ({ "swing at", "punch" }) );
    set_verbs2( ({ "swings at", "punches" }) );
    set_skill("Unarmed", 4, "strength");
    set_skill("Machine Weapons", 4, "strength");
    set("base_ac", 2);
    set("armor_class", 2);
    set("CLASS", "warrior");

    // Let's give him stuff.
    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(4);
    wear(badge);
    arm("/d/Prime/Central/weap/12mmauto.c");
    credit(10001 + random(1000)); // 1000 to 2000 coins
    set("ammo", ([ "12mm" : 2000 ]) );

    // Always the last!
    set("prevent_summon", 1);
    set("special", 4);
    set_level(17);
}

void init() {
    ::init();
    command("wield spear");
}

