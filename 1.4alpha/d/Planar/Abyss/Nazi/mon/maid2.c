/*
**File: maid2.c
*/

#include <mudlib.h>
#include "nazi.h"

inherit MONSTER ;
object the_key;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("prevent_summon", 1);

    the_key = clone_object(NAZI_OBJ+"key2.c");
    the_key->move(this_object() );
    set("author", "NSD");
    set("short", "Jeanette (Mistress of Seduction)" );
    set ("long", @EndText
 A beautiful blonde woman, with freezy hair and
green eyes. She's the ghost of one of the
women murdered by the evil lustful emperor. She's
hungry for vengeance, and will take revenge on
whomever crosses her path. She's really dangerous.
EndText
    );
    set("id", ({ "Jeanette", "jeanette", "mistress", "ghost" }) );
    set_size(6);
    set_name("Jeanette");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage",({9, 16}) );
    set("damage_type", "necromancy");
    set("weapon_name", "poisoned dagger");
    set_verbs( ({ "swing at", "peer at", "cut", "stab" }) ) ;
    set("prevent_summon", 1);
    set("natt", 2);
    set("chat_chance",5);
    set ("chat_output", ({
      "Jeanette seduces you with her beauty...\n",
      "Jeanette must not be trusted!!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);

}

/* End of File */
