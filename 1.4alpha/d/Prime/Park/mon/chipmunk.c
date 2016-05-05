#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A tiny chipmunk");
  set("long", wrap(
"A tiny chipmunk runs around on the ground. He stops often, looking about "+
"curiously."
    ) );
  set("id", ({"chipmunk"}));
  set_level(2);
  set_size(1);
  set_name("chipmunk");
  set("gender", "male");
  set("race", "rodent");
  set("damage", ({1,3}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The tiny chipmunk looks around curiously.\n",
    "The tiny chipmunk chases his tail.\n",
    }) );
  set("att_chat_output", ({
    "The chipmunk looks very frightened.\n",
    "The chipmunk looks for a place to hide.\n",
    }) );
  credit(5);
}
