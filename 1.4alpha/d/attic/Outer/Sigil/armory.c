// The old armory SUCKED ASS.  The code was *shit*.
// Chronos improved it by a tenfold.
#include <mudlib.h>
#include "sigil.h"

inherit BUYONLY_SHOP ;

void create() {
  ::create();
  seteuid(getuid());
// This defines the stock of the store the first time it's loaded.
// Every time the store resets, it _might_ start replacing items
// or adding more to the stock.
  stock = ([
     "dagger" : 6 + random(6),
     "shsword" : 4 + random(4),
     "lgsword" : 3 + random(3),
     "brsword" : random(4) + 2,
     "mace" : random(4) + 1,
     "hammer" : random(2),
     "maul" : random(2),
     "smaxe" : random(3) + 1,
     "hdaxe" : random(4) ,
     "graxe" : random(3),
     "spear" : random(3),
     "chain" : 1 + random(3),
     "ringmail" : random(4),
     "platemail" : random(3),
     "sm_shield" : random(3) + 4,
     "lg_shield" : random(3) + 4,
  ]) ;
  set ("light", 1) ;
  set("objects", ([ "garth" : "/d/Outer/Sigil/monsters/garth" ]) ) ;
  set("short", "The Armory of Sigil.") ;
  set ("long", @ENDLONG
You stand in the newly-redesigned Armory in Sigil.
Fine weapons and armours line the walls, light glinting
off the freshly polished steel.

Commands are: list, buy <item>
ENDLONG
  ) ;
  set("shopkeeper", "garth") ;
  set("shop_dir", SIGIL+"armory/") ; // dont forget the trailing /
  set("restock_msg", @ENDMSG
Garth places a few newly finished items on the shelves.
ENDMSG
  );
  set ("exits", ([
    "up" : SIGIL+"armory2.c",
    "east" : SIGIL+"petitionerst2.c" 
  ]) ) ;
  reset();
}
