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
    set("short", "A minotaur");
    set ("long", @EndText
A Horned being of great strenght. A warrior by birth.
Looks like a bull with humanoid body. He carries an axe.
EndText
    );
    set("id", ({ "minotaur", "monster", "beast", "enemy", "him" }) );
    set_size(6);
    set_name("The minotaur");
    set("prevent_summon",1);
    set("gender", "male");
    set("race", "minotaur");
    set("undead", 0);
    set("damage", ({10,20}) );
    set("weapon_name", "sharp horns");
    set_verbs( ({ "attack", "hit", "swing at", "peer at"}) ) ;
    set("natt",2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Minotaur growls wildly at you.\n",
      "Minotaur walks around the room.\n",
      "Minotaur stares at the mural and stands up straight.\n",
      "Minotaur stomps on the floor aggressively.\n",
      "Minotaur looks at you and grunts.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Minotaur glowls wildy.\n",
      "Minotaur holds his axe in front of him and screams loudly.\n",
      "Minotaur stomps on the floor agressively.\n",
      "Minotaur shakes his horns in fury.\n",
      "Minotaur groals like a beast.\n",
    }) );
    set_level(16);
    set("agressive",0);
    arm(MINA_OBJ+"bloodhorn.c");
    wear(MINA_OBJ+"tirany.c");
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
