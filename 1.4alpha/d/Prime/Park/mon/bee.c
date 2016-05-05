#include <mudlib.h>
#include <def.h>
inherit MONSTER;

void create() {
  ::create();
  seteuid(getuid());
  set("short", "A buzzing bee");
  set("long", wrap(
"A little bee buzzes about, searching for a flower to pollinate. He is "+
"covered with bright yellow and black stripes and has a sharp stinger on "+
"his tail. He seems to be harmless now, but it would be dangerous to "+
"provoke him."
    ) );
  set("id",({"bee"}));
  set_level(2);
  set_size(1);
  set_name("bee");
  set("gender", "male");
  set("race", "insect");
  set("damage", ({1,3}));
  set("weapon_name", "stinger");
  set_verbs(({"sting", "dive at"}));
  set("natt",1);
  set("chat_chance",5);
  set("chat_output",({
    "The bee buzzes about.\n",
    "The bee swarms above your head.\n",
    "The little bee searches for a flower.\n",
    }) );
  set("att_chat_output", ({
    "The bee buzzes angrily.\n",
    "The bee flits about quickly.\n",
    }) );
  credit(8);
}
