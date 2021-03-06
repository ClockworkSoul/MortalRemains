/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;
void create(){
  ::create();
  seteuid(getuid());
  set("author", "grull");
  set("short","A moaning ghoul");
  set("long","This ghoul shuffles its ways down the corridors, moaning as it moves. Your skin crawls at the thought that centuries ago, it might have been an adventurer like you, foolish enough to enter this area.\n");
  set("id", ({"ghoul", "Ghoul"}));
  set_name("Ghoul");
  enable_commands();
  set("gender", "male");
  set("race", "undead");
  set("damage", ({ 1,3 }) );
  set("weapon_name", "fists");
  set("stat/strength", 12);
  set("stat/dexterity", 10);
  set_verbs( ({ "punch at", "shove at", "push at" }) );
  set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
  set("chat_chance", 5);
  set("chat_output",({
    "The ghoul moans something incomprehensible.\n", 
      "The ghoul stares at you with hollow, soul-less eyes.\n"
      }) );
  set_size(5);
  set_level(random(4)+4);
}
