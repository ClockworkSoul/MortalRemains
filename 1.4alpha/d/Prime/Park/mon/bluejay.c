#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A bright bluejay");
  set("long", wrap(
"A bright blue bluejay nests nearby. He is the color of the sky, with a "+
"high crown of feathers and a jet black beak."
    ) );
  set("id",({"bluejay"}));
  set_level(3);
  set_size(1);
  set_name("bluejay");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({2,4}));
  set("weapon_name", "sharp beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The bluejay flies about.\n",
    "The bluejay flits above your head.\n",
    "The bluejay searches for a worm.\n",
    }) );
  set("att_chat_output", ({
    "The bluejay flits fearfully.\n",
    "The bluejay flies about quickly.\n",
    }) );
  credit(7);
}
