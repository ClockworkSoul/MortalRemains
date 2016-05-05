#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A plump worm");
  set("long", wrap(
"A worm wiggles in the dirt before you. He is plump and pink, and he moves "+
"slowly along the ground."
  ) );
  set("id", ({"worm"}));
  set_level(1);
  set_size(1);
  set_name("worm");
  set("gender", "male");
  set("race", "worm");
  set("damage", ({1,2}));
  set("weapon_name", "tiny tail");
  set_verbs(({"slap", "whap"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The plump worm wiggles about.\n",
    "The plump worm looks around curiously.\n",
    }) );
  set("att_chat_output", ({
    "The plump worm looks for a place to hide.\n",
    "The plump worm rolls up into a ball.\n",
    }) );
  credit(5);
}
