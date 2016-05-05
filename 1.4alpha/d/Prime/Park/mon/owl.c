#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A hooting owl");
  set("long", wrap(
"A wise owl looks at you curiously. He hoots occassionally and flaps his "+
"large wings."
    ) );
  set("id",({"owl"}));
  set_level(4);
  set_size(1);
  set_name("owl");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({3,5}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The owl flies about.\n",
    "The owl soars above your head.\n",
    "The owl searches for some food.\n",
    }) );
  set("att_chat_output", ({
    "The owl flaps angrily.\n",
    "The owl flies about quickly.\n",
    }) );
  credit(12);
}
