/*
**File: maid6.c
*/

#include <mudlib.h>
#include "nazi.h"

inherit MONSTER ;
object the_key;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    the_key = clone_object(NAZI_OBJ+"key6.c");
    the_key->move(this_object() );
    set("author", "NSD");
    set("short", "Angelique (Mistress of Obssession)" );
    set ("long", @EndText
A beautiful reddish-blonde woman, with curly hair and
light blue eyes. She's the ghost of one of the
women murdered by the evil lustful emperor. She's
hungry for vengeance, and will take revenge on
whomever crosses her path. She's really dangerous.
EndText
    );
    set("id", ({ "Angelique", "angelique", "mistress", "ghost" }) );
    set_size(6);
    set_name("Angelique");
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
      "Angelique seduces you with her beauty...\n",
      "Angelique must not be trusted!!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);

}

/* End of File */
