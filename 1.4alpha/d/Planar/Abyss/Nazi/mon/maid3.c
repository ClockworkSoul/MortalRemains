/*
**File: maid3.c
*/

#include <mudlib.h>
#include "nazi.h"

inherit MONSTER ;
object the_key;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;

    the_key = clone_object(NAZI_OBJ+"key3.c");
    the_key->move(this_object() );
    set("author", "NSD");
    set("short", "Sasha (Mistress of Desire)" );
    set ("long", @EndText
A beautiful woman, with auburn wavy hair and
hazel eyes. She's the ghost of one of the
women murdered by the evil lustful emperor. She's
hungry for vengeance, and will take revenge on
whomever crosses her path. She's really dangerous.
EndText
    );
    set("id", ({ "Sasha", "sasha", "mistress", "ghost" }) );
    set_size(6);
    set_name("Sasha");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage", ({9, 16}) );
    set("damage_type", "necromancy");
    set("weapon_name", "poisoned dagger");
    set_verbs( ({ "swing at", "peer at", "cut", "stab" }) ) ;
    set("prevent_summon", 1);
    set("natt", 2);
    set("chat_chance",5);
    set ("chat_output", ({
      "Sasha seduces you with her beauty...\n",
      "Sasha must not be trusted!!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);

}

/* End of File */
