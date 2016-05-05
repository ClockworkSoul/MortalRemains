#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A fuzzy bunny");
  set("long", wrap(
"A fuzzy grey bunny hops about, wrinkling his nose and twitching his "+
"ears. His little white tail appears when he jumps and resembles a "+
"perfect little cotton ball."
    ) );
  set("id", ({"bunny"}));
  set_level(3);
  set_size(1);
  set_name("bunny");
  set("gender", "male");
  set("race", "rabbit");
  set("damage", ({2,4}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The fuzzy bunny wiggles his white tail.\n",
    "The grey bunny hops about.\n",
    "The fuzzy bunny wrinkles his nose.\n",
    }) );
  set("att_chat_output", ({
    "The bunny looks very frightened.\n",
    "The bunny looks for a place to hide.\n",
    }) );
  credit(8);
}
