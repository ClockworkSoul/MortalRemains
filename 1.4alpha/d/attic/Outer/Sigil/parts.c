#include <mudlib.h>
#include "sigil.h"

inherit BUYONLY_SHOP ;

void create() {
  ::create() ;
  seteuid(getuid()) ;
// This defines the stock of the store the first time it's loaded.
// Every time the store resets, it _might_ start replacing PARTs
// or adding more to the stock.
  stock = ([
                   "severed_arm" : 2 + random(3),
                   "skull" : random(20),
                   "mutilated_hand" : 5 + random(20) ,
                   "disembodied_head" : 1 + random(2),
                   "entrails" : 1 + random(2),
  ]) ;

  set("light", 1) ;
  set("shopkeeper", "seamus" ) ;
  set("shop_dir", SIGIL+"parts/");
  set("replenish_msg", @ENDMSG
A muscular man with a strong jaw enters room, carrying a large wooden
crate.  He sets the crate down behind the counter, spits, and leaves.
ENDMSG
  ) ;
  set("objects", ([ "seamus" : SIGIL+"monsters/seamus" ]) ) ;
  set("short", "Parts + Pieces.") ;
  set ("long", @ENDLONG
This shop specializes in the morbid and macabre.  You find yourself
wondering just how much business there is for such a shop in this
town.

Commands are: list, buy <item>
ENDLONG
  );
  set ("exits", ([
    "west" : SIGIL+"turtlest2.c",
  ]));
  reset();
}
