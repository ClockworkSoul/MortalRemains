//for Assasins guild or somthing
//march 2nd 1998 (I think)

#include <mudlib.h>
inherit MONSTER ;

object bandana;

void create () {
  ::create();
  seteuid(getuid());
   set("author", "Nightmask the Dream Warden");
   set("no_attack", 1);
   set("short", "the Assasin's guild master");
   set ("long", @Foo
This is Thadius McFain the master of the Assasin's. He wears leather
armour encrusted with a sort of chain, elven you think. He has a small
vandalier a daggers, and a broadsword on his back. His cloak is pulled
up over his eyes, but you feel as if his eyes burn through you. He is
not a large man, but the scars say he is a seasoned vetran.
Foo
);
   set("id", ({ "master", "guild master", "thadius", "dickwad" }) );
   set_name("Thadius");
   set("gender", "male");
   set("race", "human");
   enable_commands() ;
   set("class", "WARRIOR"); 
   set_skill("Long Blades", 2, "Strength");
   set("natt", 2);
   set ("attack_strength", 5);
   set ("damage", ({ 2,4 }) );
   set ("weapon_name", "massive fists");
   bandana = clone_object("/d/class/rogue/Assasins/std/bandana.c");
   bandana->move(this_object());
   set ("stat/strength", 17);
   set("stat/dexterity", 16);
   set("wealth", (random(500)+200));
     set_verbs( ({ "punch at", "swing at" }) ) ;
     set_verbs2( ({ "punches at", "swings at" }) ) ;
   set ("chat_chance", 10);
   set ("chat_output", ({
       "Thadius says: Check the board for wanted players.\n",
       "Thadius says: Nightmask is lucky he's a God, I could take him.\n",
   }) );
   set ("att_chat_output", ({
   }) );
   set_level(10);
}


void init() {
   command ("equip");
   
}
