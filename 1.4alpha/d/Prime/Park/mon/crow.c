#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A jet black crow");
  set("long", wrap(
"A jet black crow struts about in front of you. His dark, shiny feathers "+
"gleam in the sunlight. He is surprisingly large and menacing for a bird."
    ) );
  set("id",({"crow"}));
  set_level(5);
  set_size(1);
  set_name("crow");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({4,6}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The crow flies about.\n",
    "The crow circles above your head.\n",
    "The crow searches for some food.\n",
    }) );
  set("att_chat_output", ({
    "The crow flaps angrily.\n",
    "The crow flies about quickly.\n",
    }) );
  credit(12);
}
