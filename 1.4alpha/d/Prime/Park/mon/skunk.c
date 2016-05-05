#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A smelly skunk");
  set("long", wrap(
"A black and white skunk struts proudly in front of you, twitching his "+
"thick tail and eyeing you carefully."
    ) );
  set("id", ({"skunk"}));
  set_level(4);
  set_size(1);
  set_name("skunk");
  set("gender", "male");
  set("race", "mammal");
  set("damage", ({3,5}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The skunk twitches his tail menacingly.\n",
    "The skunk struts about in front of you.\n",
    }) );
  set("att_chat_output", ({
    "The skunk sprays you with his scent! Yuck!\n",
    "The skunk sprays his scent into the air.\n",
    }) );
  credit(10);
}
