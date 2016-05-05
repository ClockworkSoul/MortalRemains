/*
**File: maid1.c
*/

#include "nazi.h"
#include <mudlib.h>

inherit MONSTER ;
object the_key;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    set("prevent_summon", 1);
    enable_commands() ;

    the_key = clone_object(NAZI_OBJ+"key1.c");
    the_key->move(this_object() );
    set("author", "NSD");
    set("short", "Hellen (Mistress of Passion)" );
    set ("long", @EndText
A beautiful red-head woman, with straight hair and
brown eyes. She's the ghost of one of the
women murdered by the evil lustful emperor. She's
hungry for vengeance, and will take revenge on
whomever crosses her path. She's really dangerous.
EndText
    );
    set("id", ({ "Hellen", "hellen", "mistress", "ghost" }) );
    set_size(6);
    set_name("Hellen");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage", ({ 3, 9 }) );
    set("damage_type", "necromancy");
    set("armor_class", -2);
    set("spell_points", 300);
    set("max_sp", 300);
    set("weapon_name", "poisoned dagger");
    set_verbs( ({ "swing at", "peer at", "cut", "stab" }) ) ;
    set("prevent_summon", 1);
    set("natt", 2);
    set("chat_chance",5);
    set ("chat_output", ({
      "Hellen seduces you with her beauty...\n",
      "Hellen must not be trusted!!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);
}

/* End of File */
