#include <mudlib.h>
#include "../GenericLib.h"

inherit ARMOR;
inherit GLibDir+"equip_generic_monster.c";

void create() {
  seteuid(getuid());
  set_equip_properties(random_equip_type(), random_equip_material());
  set_armor_type(lower_case(equip_type));
}


