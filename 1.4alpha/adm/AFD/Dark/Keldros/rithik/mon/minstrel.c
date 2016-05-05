#include <mudlib.h>
#include "../defs.h"

inherit "/u/w/waxer/fun/mon/wander.c";

void create() {
  seteuid(getuid());
  ::create();
  set("short", "traveling minstrel");

  set("long", @ENDLONG
This is a small human wearing colorful garb and a warm smile.
ENDLONG
  );
  set_alignment(300);
  set_name("traveling minstrel");
  set("id", ({
    "minstrel",
    "traveling minstrel",
  }));
  
  credit(120 );
  set("damage", ({ 5, 15 }) );
  set("armor_class", 8);
  set("wander", ({ "north", "east", "south", "west" }));
  set("wander_chance", 5);
  set("forbidden_rooms",
      ({
        ROOMS(zathril3),
        ROOMS(nlane),
        ROOMS(stairs),
      }));
  clone_object(OBJ(sbook.c))->move(TO);
  set("attack_strength", 18);
  set("race", "human");
  set("attrib1", "short");  set("attrib2", "slender");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "thwack",
    "jab",
}));
  
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(4);
  set("chat_chance", 1);
  set("chat_output", ({
    "The minstrel sings a happy tune.\n",
    "The minstrel reads a book of songs happily to himself.\n",
  }) );
 
}
