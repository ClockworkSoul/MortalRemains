#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A green centipede");
  set("long", wrap(
"A bright green centipede crawls along he ground. You start counting his "+
"tiny legs but give up quickly."
  ) );
  set("id", ({"centipede"}));
  set_level(1);
  set_size(1);
  set_name("centipede");
  set("gender", "male");
  set("race", "insect");
  set("damage", ({1,2}));
  set("weapon_name", "tiny teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The little centipede scurries about.\n",
    "The little centipede looks around curiously.\n",
    }) );
  set("att_chat_output", ({
    "The centipede looks for a place to hide.\n",
    "The little centipede flexes his puny muscles.\n",
    }) );
  credit(5);
}
