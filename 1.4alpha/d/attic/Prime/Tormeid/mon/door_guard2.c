// These door guards specifically guard the audience chamber of the King.
#include "../defs.h"

static string DIR ;
inherit GUARD ;
int set_dir(string dir) ;

create(){
  ::create() ;
  set("short", "a royal elite guard") ;
  set("long", @ENDLONG
This guard looks large and powerful, and quite capable of his job of
defending the royal family.  He carefully watches every move you make
while you move through the area.
ENDLONG
  );
  set("id", ({ "guard", "elite guard", "royal guard" }) );
  set_level(55) ;
  set("natt", 2) ;
  set_size(7) ;
  arm(WEAPONS(elite_weapon), "ELITE_WEAPON") ;
  wear(ARM(elite_plate), "plate") ;
  wear(ARM(elite_cloak), "cloak") ;
  wear(ARM(elite_helm), "helm") ;
  set_skill("Long Blades", 3, "strength") ;
  set_skill("Short Blades", 3, "strength") ;
  set_skill("Polearms", 3, "strength") ;
  set_skill("Clubbing Weapons", 3, "strength") ;
  set_skill("Shield Style", 1, "dexterity") ;
  wear(ARM(elite_gauntlets), "gauntlets") ;
  wear(ARM(hlboots), "boots");
  if (!random(3)) clone_object(OBJ(royal_key))->move(TO) ;
  delete("pursuing") ;
  set_dir("east") ;
}

int set_dir(string dir) {
  if (!dir) return 0 ;
  DIR = dir ;
  return 1;
}

void init() {
  add_action("stop_move", "scout") ;
  add_action("stop_move", "go") ;
  add_action("stop_move", "sneak") ;
}

int stop_move(string dir) {
  if (wizardp(TP)) return 0 ;
  if (!dir) return 0 ;
  if (dir != DIR) return 0 ;
  if (TP->query("invisible")) {
      write("Since you are invisible, you walk right past the guard.\n") ;
     return 0 ;
  }
   write("The guard says: No one shall disturb the Royal Family!\n") ;
   write("The guard stands in your way defiantly.\n") ;
  say(TPN+ " tries to move "+DIR+", but the elite guard stops "+
  objective(TP->query("gender")) + 
   ".\n") ;
  return 1;
}

