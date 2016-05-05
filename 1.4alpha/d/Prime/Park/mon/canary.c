#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A yellow canary");
  set("long", wrap(
"A bright yellow canary sings a song nearby. His feathers are the color "+
"of sunshine, and his merry tune puts a smile on your face."
    ) );
  set("id",({"canary"}));
  set_level(2);
  set_size(1);
  set_name("canary");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({1,3}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The canary sings a merry tune.\n",
    "The canary flits above your head.\n",
    "The canary searches for a worm.\n",
    }) );
  set("att_chat_output", ({
    "The canary flits fearfully.\n",
    "The canary flies about quickly.\n",
    }) );
  credit(7);
}
