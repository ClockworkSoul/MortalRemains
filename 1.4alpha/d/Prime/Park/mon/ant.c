#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A little black ant");
  set("long", wrap(
"A little black ant scurries about looking for food. He is quite small and "+
"looks like he would be defenseless in a fight."
  ) );
  set("id", ({"ant"}));
  set_level(1);
  set_size(1);
  set_name("ant");
  set("gender", "male");
  set("race", "insect");
  set("damage", ({1,2}));
  set("weapon_name", "tiny teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The little ant scurries about.\n",
    "The little ant looks around curiously.\n",
    }) );
  set("att_chat_output", ({
    "The little ant looks for a place to hide.\n",
    "The little ant flexes his puny muscles.\n",
    }) );
  credit(5);
}
