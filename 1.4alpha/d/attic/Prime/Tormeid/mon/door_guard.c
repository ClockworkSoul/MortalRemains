// These door guards can be placed anywhere.
#include "../defs.h"

static string DIR ;
int set_dir(string dir) ;
inherit GUARD ;

create(){
  ::create() ;
  set("short", "a castle guard") ;
  set("long", @ENDLONG
The guard eyes you stonily as you move through the area.
ENDLONG
  );
  set("id", ({ "guard", "castle guard", "door guard" }) ) ;
  set_level(25) ;
  arm(WEAPONS(longswd), "sword") ;
  set_size( 6) ;
  wear(ARM(chainmail), "chainmail");
  wear(ARM(medshield), "shield") ;
  wear(ARM(lgloves), "gloves");
  wear(ARM(helmet), "helmet");
  set_skill("Long Blades", 2, "strength") ;
  wear(ARM(hlboots), "boots");
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
    write("Since you are invisible, you sneak right by the guard.\n") ;
   return 0 ;
  }
  write("The guard stands in your way defiantly.\n");
  say(TPN+" tries to move "+DIR+", but a guard stops him.\n") ;
  return 1;
}

