/*
**File: minotaur1.c
** Author: Ragevortex
** Updated by: Lady Nsd (july 2000)
*/

#include <mudlib.h>
#include "mina.h"

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "ragevortex");
    set ("short", "Bloodluster");
    set ("long", @EndText
A Savage bloodlusting son of a minotaur !! Born to kill and enjoy
doing it. Looks like a huge red bull with strong humanoid body.
He carries a wicked axe.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES

    set("id", ({ "minotaur", "monster", "beast", "enemy", "him",
      "warrior", "luster", "bloodluster" }) );
    set_size(9);
    set_name("Bloodluster");
    set("prevent_summon",1);
    set("gender", "male");
    set("race", "minotaur");
    set("undead", 0);
    set("damage", ({15,40}) );
    set("weapon_name", "sharp horns");
    set_verbs( ({ "attack", "hit", "swing at", "peer at", "chunk at", "stab at" }) );
    set("natt",2);
    set("chat_chance", 5);
    set("chat_output", ({
      "Minotaur stomps on the floor aggressively.\n",
      "Minotaur looks at you and grunts.\n",
      "Minotaur smells your blood.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Minotaur glowls wildy.\n",
      "Minotaur holds his axe in front of him and screams loudly.\n",
      "Minotaur stomps on the floor agressively.\n",
      "Minotaur shakes his horns in fury.\n",
      "Minotaur groals like a beast.\n",
      "Minotaur licks the blood from his Bloodhorn.\n",
    }) );

    // set_level() is one of Cyanide's brainstorms. what it does is 
    // basically everything, you need this line if you plan to make a 
    set_level(35);
    set("aggressive",0);
    arm(MINA_OBJ+"goldthunda.c");
    wear(MINA_OBJ+"tirany.c");
    wear(MINA_OBJ+"metalmask.c");
}
void die() {
    object horns;
    horns = clone_object(MINA_OBJ+"polished.c");
    if (horns)
	horns->move( this_object() );
    ::die() ;
    return ;
}

/* End of File */
