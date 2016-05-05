/*
**File: minocow.c
** Author: Ragevortex
** Updated by: Lady Nsd (july 2000)
*/

#include <mudlib.h>
#include "mina.h"

inherit MONSTER;
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "ragevortex");
    set("short", "a Minocow");
    set ("long", @EndText
The Female version or a minotaur. The Minocow.
It has a great curvy woman body but also has the head of a cow.
Yes a cow... also carries  club cause all the mino's are warriors
and she aint no exeption.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"cow", "minocow", "her", "enemy"}) );
    set_size(5);
    set_name("The Minocow");
    set("gender", "female");
    set("race", "minocow");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({8,15}) );
    set("weapon_name", "club");
    set_verbs( ({ "attack", "hit", "swing at", "peer at"}) ) ;
    set("natt",2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Minocow goes MOOOOOO!.\n",
      "Minocow is looking for some grass.\n",
      "Minocow wiggles her hips seductively as she walks.\n",
      "Minocow sings MOOOO MOOO MOOOOO MOO MOOOOO!!!.\n",
      "Minocow twirls her club as if it were a baton.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Minocow MOOS loudly.\n",
      "Monocow twirls her club as if it were a baton.\n",
      "Minocow squirts you with milk.\n",
      "Minocow winks at you seductively.\n",
      "Minocow MOOS angryly.\n",
    }) );
    set_level(10);
    set("agressive",0);
    arm(MINA_OBJ+"hornclub.c");
    wear(MINA_OBJ+"tirany.c");
}

void die() {
    object milk;
    object horns;
    milk = clone_object(MINA_OBJ+"milk.c");
    horns = clone_object(MINA_OBJ+"polished.c");
    if (milk)           // This ensures we cloned it right.
	milk->move( this_object() );
    if (horns)
	horns->move( this_object() );
    say(wrap(
	"The Minocow lets out a mornfull MOOOOOO as she falls to the ground...she pours one last glass of MILK before dying."
      )) ;
    ::die() ;
    return ;
}
/* End of File */
