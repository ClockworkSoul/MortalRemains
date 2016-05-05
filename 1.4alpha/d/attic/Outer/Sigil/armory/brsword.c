// Special item, only found in the Sigil armory.
#include <mudlib.h>
//#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a broadsword");
  set("long", @ENDLONG
A broadsword from the Sigil Armory.
ENDLONG
  );
  set("id", ({ "sword", "broadsword" }));
  set("name", "broadsword");
  set("value", 350);
  set("mass", 86) ;
  set("bulk", 9) ;
  set("weapon", 8) ;
  set("damage", ({ 3, 7 }));
  set_weapon_type("sword/long") ;
  set_material_type("metal/steel") ;
  set_bonus(0,0,0);
  set_verbs(({ "swing at", "attack", "slash at" }) );
  set("size", 6);
  set_verbs2(({ "swings at", "attacks", "slashes at" }) );
} 
