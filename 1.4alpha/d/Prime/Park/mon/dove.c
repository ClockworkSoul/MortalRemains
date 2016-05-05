#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A snow-white dove");
  set("long", wrap(
"A snowy white dove gracefully glides before you, landing softly on the "+
"ground. His small black eyes peer out curiously, and he turns his head to "+
"the side in contemplation."
    ) );
  set("id",({"dove"}));
  set_level(3);
  set_size(1);
  set_name("dove");
  set("gender", "male");
  set("race", "bird");
  set("damage", ({2,4}));
  set("weapon_name", "beak");
  set_verbs(({"poke", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The dove glides about.\n",
    "The dove hovers above your head.\n",
    "The dove searches for food.\n",
    }) );
  set("att_chat_output", ({
    "The dove flits angrily.\n",
    "The dove flies about quickly.\n",
    }) );
  credit(10);
}
