#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A young fawn");
  set("long", wrap(
"A young fawn stands before you, perfectly still. Her eyes are large and "+
"brown, and her light tan fur is dotted with white spots."
    ) );
//set("id", ({"fawn}));
set("id", ({ "fawn" }) );
  set_name("fawn");
  set_level(4);
  set_size(3);
  set("gender", "female");
  set("race", "deer");
  set("damage", ({3,5}));
  set("weapon_name", "teeth");
  set_verbs(({"bite", "gnaw"}));
  set("natt", 1);
  set("chat_chance", 5);
  set("chat_output", ({
    "The young fawn stands perfectly still.\n",
    "The young fawn looks stunned.\n",
    }) );
  set("att_chat_output", ({
    "The fawn jumps fearfully.\n",
    "The fawn whimpers softly.\n",
    }) );
  credit(10);
}
