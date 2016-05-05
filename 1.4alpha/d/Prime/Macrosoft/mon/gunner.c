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
    set("short", "a highly-trained warrior");
    set("long", @EndText
This is a very, very large sweaty human apparantly testing out some very,
very large bizarre experimental weapon. He grins evilly as he looks at 
you.
EndText
    );
    set("race", "human");
    set("gender", "male");
    set_name("warrior");
    set("id", ({ "warrior", "highly-trained warrior" }) );
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );

    set("stat", ([
      "strength" : 18,
      "constitution" : 19,
      "dexterity" : 19
    ]) );

    set ("damage", ({ 1, 6 }) );
    set("base_ac", 4);
    set("chat_chance", 10);
    set("chat_output", ({   
    }));
    set("att_chat_output", ({
      "The warrior says [to you]: C'mon wimp!\n",
      "The warrior says [to you]: Come get some!\n",
    }));

    // Neat trick, huh?
    guns = get_dir(MS_WEAP("vh_*.c"));

    ob = clone_object (MS_WEAP(guns[ random(sizeof(guns)) ]) );
    if (ob) {
	set_skill(ob->query("weapon_type"), 2, "strength");
	set("ammo", ([ ob->query("ammo_type") : 100 ]) );
	arm(ob);

    }                                   
    set("special", 3);

    set_level(16);
    credit( (int)query("max_hp") / 2 );
}

int ammo_debit(int i) { return 1; }  

/* EOF */
