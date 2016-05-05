#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A tiny sparrow");
  set("long", wrap(
"A tiny sparrow hops about on the ground, searching for food. He stops "+
"occassionally, looking your direction and cocking his head curiously."
    ) );
  set("id",({"sparrow"}));
  set_level(2);
  set_size(1);
  set_name("sparrow");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({1,3}));
  set("weapon_name", "tiny beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The sparrow flies about.\n",
    "The sparrow flits above your head.\n",
    "The sparrow searches for a worm.\n",
    }) );
  set("att_chat_output", ({
    "The sparrow flits fearfully.\n",
    "The sparrow flies about quickly.\n",
    }) );
  credit(5);
}
