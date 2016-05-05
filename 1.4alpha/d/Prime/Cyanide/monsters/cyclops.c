/*
** Cyclops.c
** Cyanide - 29 Jan 98
*/

#include <mudlib.h>
#include "../cy.h"

inherit MONSTER;

void create() {
    object weapon;

    ::create();
    seteuid(getuid());
    set("ammo", ([]) );

    // ID stuff.
    set("author", "cyanide");
    set("id", ({ "cyclops", "giant" }) );
    set("short", "a cyclops");
    set("long", @EndLong
Through his overpowering body odor, you can barely make out
his features: A single large, red eye dominates the center of
his forehead. He is dressed in ragged animal hides which seem
to smell of equal parts dirt and dung.
EndLong
    );
    set_name("cyclops");

    // Body stuff
    set("race", "cyclops");
    set("gender", "male");
    set_size(20);
    set_align("ce");
    set("stat/strength", 20);
    set("stat/intelligence", random(6)+5);

    // Combat stuffs	
    set("damage", ({ 6, 15 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "swing at", "punch" }) );
    set_verbs2( ({ "swings at", "punches" }) );
    set_skill("Clubbing Weapons", 2, "strength");
    set_skill("Polearms", 3, "strength");
    set("base_ac", 2);
    set("armor_class", 2);
    set("CLASS", "warrior");

    // Let's give him stuff.
    weapon = clone_object("./weapons/big_spear.c");
    if (weapon) weapon->move(TO);
    credit(1001 + random(1000)); // 1000 to 2000 coins

    // Always the last!
    set_level(13);
    arm(OBJ+"/bonespear.c");
}

void init() {
    ::init();
    command("wield spear");
}

