#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A creepy spider");
  set("long", wrap(
"This dark brown spider is large and quite scary! He scurries about on the "+
"ground, and you inadvertantly jump when he heads in your direction."
    ) );
  set("id", ({"spider"}));
  set_level(3);
  set_size(1);
  set_name("spider");
  set("gender", "male");
  set("race", "arachnid");
  set("damage", ({2,4}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The creepy spider scurries about on the ground.\n",
    "The creepy spider looks up at you menacingly.\n",
    }) );
  set("att_chat_output", ({
    "The spider runs around angrily.\n",
    "The spider crawls toward you threateningly.\n",
    }) );
  credit(10);
}
