#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A red cardinal");
  set("long", wrap(
"A dark red cardinal searches for food. His feathers gleam in the sunlight, "+
"making him one of the most beautiful birds you've ever seen."
    ) );
  set("id",({"cardinal"}));
  set_level(3);
  set_size(1);
  set_name("cardinal");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({2,4}));
  set("weapon_name", "sharp beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The cardinal flies about.\n",
    "The cardinal flits above your head.\n",
    "The cardinal searches for a worm.\n",
    }) );
  set("att_chat_output", ({
    "The cardinal flits fearfully.\n",
    "The cardinal flies about quickly.\n",
    }) );
  credit(7);
}
