// This item is only found in the Sigil Armory.
#include <mudlib.h>
//#include "../defs.h"

inherit ARMOR ;

void create() {
  seteuid(getuid());
  set ("id", ({ "ringmail" }) ) ;
  set ("short", "ringmail") ;
  set("long", @ENDLONG
A suit of ringmail from the Sigil Armory.
ENDLONG
  );
  set("mass", 120);
  set("value", 650);
  set_armor_type("ring mail") ;
  set("armor",7);
  set("size", 6);
}



