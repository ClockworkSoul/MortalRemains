/*
**File: edrich.c
*/

#include "nazi.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "Lord Edrich Van Vraaden (the Lustful Emperor)" );

    // This is the text you get when you look at the monster.
    set ("long", @EndText
Edrich is a really tall man of nordic ancesters.
He's irressistably handsome, with long-straight
black hair and light gray eyes. He has a broad back
and shoulders. Definitely, no woman could refuse
him. He's strong, and merciless.
EndText
    );
    set("id", ({ "lord", "edrich", "van vraaden", "emperor" }) );
    set_size(7);
    set_name("Lord Edrich");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("lore_type", "monster lore");
    set("damage", ({11, 18}) );
    set("damage_type", "slashing");
    set("weapon_name", "sword of lust");
    set_verbs( ({ "swing at", "peer at", "cut", "wound" }) );
    set_verbs2( ({ "slashes" }) );
    set("prevent_summon", 1);
    set("natt", 2);
    set("armor_class", 5);
    set("CLASS", "warrior");
    set("weap_resist", 2);
    set_skill("one weapon style", 5, "dexterity");
    set("chat_chance", 30);
    set ("chat_output", ({
      "Lord Edrich is seducing a new maiden.\n",
      "Lord Edrich kisses the maiden's neck with passion...\n",
      "Lord Edrich nibbles on the maiden's ear...\n",
      "Lord Edrich touches the maiden in a way she's never been touched before...\n",
      "Lord Edrich feels uncomftable suddenly.\n",
      "Lord Edrich peers madly at you.\n",
      "Lord Edrich says [to you] : How dare you interrupt  my intimate moment?\n",
      "Lord Edrich says [to you] : You'll pay for this!!!\n",
      "Lord Edrich says [to you] : No one interrupts what I do best"+
      " and lives to talk about it!!\n",
      "Lord Edrich says [to you] : Prepare to die!!!\n",
      "Lord Edrich dresses and wields his sword.\n",
    }) );
    set ("att_chat_output", ({
    }) );
    arm(NAZI_OBJ+"lustsword.c");
    set_level(20);

}

/* End of File */
