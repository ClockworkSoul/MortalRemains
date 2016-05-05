/*
** FILE: gunner.c
** PURPOSE: The primary monster on floor 5 of the Macrosoft Building.
** CREDITS/CHANGES:
**    3/2/2000     Cyanide's depraved mind created this file.
*/

#include "macrosoft.h"   

inherit MONSTER;

void create() {
    string *guns;
    object ob;

    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("prevent_summon", 1);
    set("short", "Professor Doom, the Head of Research and Development");
    set("long", @EndText
The boss of this level is a some kind of very large humanoid, his features
hidden under a highly advanced suit of black cerametal full body armor.
EndText
    );
    set("race", "human");
    set("gender", "male");
    set_name("Professor Doom");
    set("id", ({ "doom", "professor", "boss", "head" }) );
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );

    // BAD ASS.
    set("stat", ([
      "strength" : 18,
      "constitution" : 16,
      "dexterity" : 16,
    ]) );

    set("chat_chance", 10);
    set("chat_output", ({   
      "The professor wipes some dirt from his armor.\n",
      "The professor adjusts his helmet.\n",
      "The professor examines his weapon.\n",
    }));

    wear(MS_ARMOR("cec300"));

    ob = clone_object (MS_WEAP("s_autocannon.c") );
    if (ob) {
	set_skill(ob->query("weapon_type"), 4, "strength");
	set("ammo", ([ ob->query("ammo_type") : random(200) + 400 ]) );
	arm(ob);
    }

    set("special", 8);

    set_level(32);
    credit( (int)query("max_hp") );
}

int ammo_debit(string str, int i) {
    return 1;
}

/* EOF */
