#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "queen's guard");
  enable_commands();
  set("long", @ENDLONG
This giant ant is covered with fierce spines portruding out of every joint in his
body.  Just looking at him runs shivers up your spine.
ENDLONG
  );
  set_name("queen's guard");
  set("id", ({
    "guard_1",
    "guard",
    "ant",
    
  }));
  arm(WEAPONS(bronze), "shortsword");
  credit(random(25) + random(25) + 5 );
  set("damage", ({ 3, 11 }) );
  set("armor_class", 8);

  
  set("attack_strength", 12);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "bronze shortsword");
  set_verbs( ({
    "slice at",
    "thrust at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(3);
  
  set("forgetful", 1);
  
}
