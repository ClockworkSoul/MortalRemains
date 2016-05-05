#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A red-breasted robin");
  set("long", wrap(
"A red-breasted robin flies about in front of you. He is quite plump and "+
"occassionally sings a merry tune."
    ) );
  set("id",({"robin"}));
  set_level(3);
  set_size(1);
  set_name("robin");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({2,4}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The robin flies about.\n",
    "The robin flits above your head.\n",
    "The robin searches for a worm.\n",
    }) );
  set("att_chat_output", ({
    "The robin flits angrily.\n",
    "The robin flies about quickly.\n",
    }) );
  credit(10);
}
