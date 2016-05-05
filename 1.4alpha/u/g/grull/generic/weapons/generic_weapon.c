#include <mudlib.h>
#include "../GenericLib.h"

inherit WEAPON;
inherit GLibDir+"arm_generic_monster.c";

void create(){
  string generic_weapon_type, generic_weapon_material;
  seteuid(getuid());
  generic_weapon_type = random_weapon_type();
  generic_weapon_material = random_weapon_material();
  set_weapon_properties(generic_weapon_type, generic_weapon_material);
}
