/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;
void create(){
  ::create();
  seteuid(getuid());
  set("author", "grull");
  set("short","A bored looking human");
  set("long", "This human has given up all hope of escaping the prison. His beard is almost long enough to touch the floor. The remainants of his clothes fall tattered over his frame, and he looks at you sadly.\n");
  set("id", ({"Man", "man", "Human", "human"}) );
  set_name("Human");
  enable_commands();
  set("gender", "male");
  set("race", "human");
  set("damage", ({ 1,2 }) );
  set("weapon_name", "fists");
  set("stat/strength", 10);
  set("stat/dexterity", 14);
  set_verbs( ({ "punch at", "shove at", "push at" }) );
  set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
  set("chat_chance", 5);
  set("chat_output",
      ({
	"The human begs you to take him with you.\n",
	  "Muttering to himself, the human twiddles his thumbs.\n",
	  }) );
  set_size(5);
  set_level(random(4)+4);
}


