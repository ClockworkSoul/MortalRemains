#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "snot-nosed kid");
  enable_commands();
  set("long", @ENDLONG
This kid looks like trouble on two feet and is covered with paint.
ENDLONG
  );
  set_alignment(-100);
  set_name("Katy");
  set("id", ({
    "kid_4",
    "kid",
    "student",
    "katy",  
  }));
  
  credit(5);
  set("damage", ({ 1, 6 }) );
  set("armor_class", 0);

  clone_object(OBJ(tbook.c))->move(TO);
  set("hit_points", 30);
  set("attack_strength", 2);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "red-haired");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
 set_verbs2( ({
    "punches",
    "tap",
}));

  set_skill("defense", 0, "dexterity");
  set_skill("attack", 0, "strength");
  set_level(1);
  set("chat_chance", 4);
  set("chat_output", ({
    "Katy screams: I hate you, I hate you, I hate you!\n",
    
    
   
  }) );
  set("forgetful", 1);
  
}
