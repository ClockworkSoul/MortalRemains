/*
**File: maid5.c
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
    the_key = clone_object(NAZI_OBJ+"key5.c");
    the_key->move(this_object() );
    set("author", "NSD");
    set("short", "Gina (Mistress of Perversion)" );
    set ("long", @EndText
A beautiful ash-blonde woman, with wavy hair and
light gray eyes. She's the ghost of one of the
women murdered by the evil lustful emperor. She's
hungry for vengeance, and will take revenge on
whomever crosses her path. She's really dangerous.
EndText
    );
    set("id", ({ "Gina", "gina", "mistress", "ghost" }) );
    set_size(6);
    set_name("Gina");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage", ({9, 16}) );
    set("damage_type", "necromancy");
    set("weapon_name", "poisoned dagger");
    set_verbs( ({ "swing at", "peer at", "cut", "stab" }) ) ;
    set("natt", 2);
    set("chat_chance",5);
    set ("chat_output", ({
      "Gina seduces you with her beauty...\n",
      "Gina must not be trusted!!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    // wear() and arm() statements.
    set_level(16);

}

/* End of File */
