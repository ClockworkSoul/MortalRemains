#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A bright red ladybug");
  set("long", wrap(
"A brightly colored ladybug crawls about the ground. She has red wings "+
"covered with tiny black dots. She occassionally takes off and flies "+
"gracefully through the air."
    ) );
  set("id", ({"ladybug"}));
  set_level(1);
  set_size(1);
  set_name("ladybug");
  set("gender", "female");
  set("race", "insect");
  set("damage", ({1,2}));
  set("weapon_name", "tiny teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The little ladybug crawls about on the ground.\n",
    "The bright red lady bug takes off and flies about.\n",
    }) );
  set("att_chat_output", ({
    "The little ladybug tries to fly away.\n",
    "The little ladybug scurries about fearfully.\n",
    }) );
  credit(5);
}
