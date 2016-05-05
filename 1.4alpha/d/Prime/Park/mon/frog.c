#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A green frog");
  set("long", wrap(
"A green frog sits nearby on the ground. He looks around curiously and "+
"makes loud, strange sounds. You wonder if this is some sort of mating "+
"call."
   ) );
  set("id", ({"frog"}));
  set_level(3);
  set_size(1);
  set_name("frog");
  set("gender", "male");
  set("race", "amphibian");
  set("damage", ({2,4}));
  set("weapon_name", "tiny teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The frog ribbits loudly.\n",
    "The frog cocks his head curiously.\n",
    }) );
  set("att_chat_output", ({
    "The frog ribbits fearfully.\n",
    "The frog leaps about in fright.\n",
    }) );
  credit(9);
}
