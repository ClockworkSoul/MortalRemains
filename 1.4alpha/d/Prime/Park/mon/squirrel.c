#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A brown squirrel");
  set("long", wrap(
"A grey squirrel hunts for nuts on the ground. His large brown tail "+
"flits about as he runs from place to place."
    ) );
  set("id", ({"squirrel"}));
  set_level(3);
  set_size(1);
  set_name("squirrel");
  set("gender", "male");
  set("race", "rodent");
  set("damage", ({2,4}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The squirrel searches for nuts.\n",
    "The squirrel twitches his tail.\n",
    }) );
  set("att_chat_output", ({
    "The squirrel looks very frightened.\n",
    "The squirrel looks for a place to hide.\n",
    }) );
  credit(8);
}
