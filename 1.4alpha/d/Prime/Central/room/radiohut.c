#include <mudlib.h>
#include "central.h"

inherit BUYONLY_SHOP ;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("objects", ([ "jeff" : M_MON+"jeff.c" ]) );
    reset();

    // This defines the stock of the store the first time it's loaded.
    // Every time the store resets, it _might_ start replacing PARTs
    // or adding more to the stock.
    stock = ([
    "flashlight" : 20,
    "headset" : 5+random(6),
  ]) ;

    set("author", "cyanide");
    set("light", 1) ;
    set("shopkeeper", "jeff");
    set("shop_dir", M_OBJ);
    set("restock_msg", wrap(
	"A lanky man in a brown UPS jumpsuit enters the shop carrying "+
	"a large cardboard box. He sets the box on the counter, makes "+
	"a note on his pad, and leaves."
      ) );
    set("short", "Radio Hut");
    set ("long", @ENDLONG
This shop specializes in electronic devices and gadgets. Hundreds
of items, from a stunning array of telephones to ear-devastaing
stereo equipment is sold here.

Commands are: list, buy <item>
ENDLONG
    );
    set("item_desc", ([
      "devices" : "Hundreds of little plastic gadgets.\n", 
      "gadgets" : "Hundreds of little platic devices.\n",
      "telephones" : "You've never seen so many expensive phones.\n",
      "equipment" : "Stereo equipment from every conceivable manufacturer.\n",
    ]) );
    set ("exits", ([
      "west" : M_ROOM+"road0_1.c",
    ]));
    reset();
}
