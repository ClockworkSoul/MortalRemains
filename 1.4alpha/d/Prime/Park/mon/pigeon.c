#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A grey pigeon");
  set("long", wrap(
"A large grey pigeon pecks about on the ground, looking for something to "+
"eat."
    ) );
  set("id",({"pigeon"}));
  set_level(3);
  set_size(1);
  set_name("pigeon");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({2,4}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The pigeon flies about.\n",
    "The pigeon flaps his wings.\n",
    "The pigeon pecks about on the ground.\n",
    }) );
  set("att_chat_output", ({
    "The pigeon flaps fearfully.\n",
    "The pigeon flies about quickly.\n",
    }) );
  credit(7);
}
