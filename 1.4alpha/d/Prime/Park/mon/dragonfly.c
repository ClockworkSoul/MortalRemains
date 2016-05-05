#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A creepy dragonfly");
  set("long", wrap(
"A large dragonfly soars about above you head. You know it's just an insect "+
"but shiver nonetheless."
  ) );
  set("id", ({"dragonfly"}));
  set_level(2);
  set_size(1);
  set_name("dragonfly");
  set("gender", "male");
  set("race", "insect");
  set("damage", ({1,3}));
  set("weapon_name", "tiny wing");
  set_verbs(({"slap", "hit"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The creepy dragonfly flies about.\n",
    "The dragonfly looks around curiously.\n",
    }) );
  set("att_chat_output", ({
    "The dragonfly looks for a place to hide.\n",
    "The dragonfly buzzes angrily.\n",
    }) );
  credit(7);
}
