#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A slimy toad");
  set("long", wrap(
"A slimy green toad hops about the ground. His green and black skin glistens "+
"in the light."
    ) );
  set("id", ({"toad"}));
  set_level(2);
  set_size(1);
  set_name("toad");
  set("gender", "male");
  set("race", "amphibian");
  set("damage", ({1,3}));
  set("weapon_name", "tiny teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The tiny toad hops about.\n",
    "The toad's green skin glistens in the light.\n",
    }) );
  set("att_chat_output", ({
    "The toad tries to hop away and fails.\n",
    "The toad looks up fearfully.\n",
    }) );
  credit(6);
}
