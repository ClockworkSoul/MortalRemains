
#include "../Prime.h"

inherit MONSTER;

int warned;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a two-headed ogre");
  enable_commands();
  set("long", @ENDLONG
Some masters of lore might have mistaken this for an ettin,
but judging by its size and obvious intelligence, it is an ogre.
Magical forces must have been used to create such an ugly and
mutated beast.
ENDLONG
  );
  set_alignment(-20);
  set_name("beldogar");
  set("id", ({
    "ogre",
    "beldogar",
  }));
  
  credit(20 + random(160));
  set("damage", ({ 18, 45 }) );

  arm(D_PRIMEO+"/rock_hammer.c", "hammer");
  wear(D_PRIMEO+"/loin_cloth.c", "loincloth");
  set("attack_strength", 20);
  set("race", "ogre");
  set("attrib1", "two-headed");  set("attrib2", "mutant");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "attempt to crush",
    "bash at",
}));
  set_verbs2( ({
    "attempts to crush",
    "bashes at",
}));
  set_skill("defense", 22, "dexterity");
  set_skill("attack", 38, "strength");
  set_level(12);
  set("chat_chance", 3);
set("chat_output", ({
    "One of Beldogar's heads looks at you in bewilderment.\n",
    "Beldogar argues with himself in an unknown language.\n",
    "Beldogar's left side heaves and hits his right side's head\nhard with a heavy hammer.\n",
  }) );
}
void init(){
  add_action("enter", "enter");
  }
  
  
  int enter(){
    if(warned > 0){
       write(" One of Beldogar's heads screams \"Me said no, ugly "+TP->query("race")+"\".\n");
       kill_ob(TP);
       return 1;
       }
    write("Beldogar doesn't let you hear his wonderful home.\n");
    warned++;
    return 1;
    }
