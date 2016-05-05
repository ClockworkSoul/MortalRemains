#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A large woodpecker");
  set("long", wrap(
"A large woodpecker with a sharp, pointed beak rests on a tree. He is taking "+
"a break from the hole he is making in the wood."
    ) );
  set("id",({"woodpecker"}));
  set_level(4);
  set_size(1);
  set_name("woodpecker");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({3,5}));
  set("weapon_name", "sharp beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The woodpecker flies about.\n",
    "The woodpecker flies above your head.\n",
    "The woodpecker makes a hole in a tree.\n",
    }) );
  set("att_chat_output", ({
    "The woodpecker flaps fearfully.\n",
    "The woodpecker flies about quickly.\n",
    }) );
  credit(13);
}
