// An example shop, which inherits the standard shop object.
// All shops that inherit the standard shop should call ::create() BEFORE
// loading shop objects, because euid is set in ::create. It's easiest to
// just make ::create() the first call in the local create proc.

#include <money.h>
#include <path.h>

inherit "/std/shop" ;

void create() {
  ::create();
  set("light", 1);
  set("short", "Vieillere Shop");
  set("long", @Endtext
This small shop in Vieillere is definitely not in the best possible
condition.  A crumbling stone wall holds up a makeshift tin roof to
protect the place from the elements.  A counter with a broken display
case stands to one side, showing off the items which are for sale.
To use the shop, you can: list, buy, value, and sell.
Endtext
  );
  set("item_desc", ([
    "wall" : "It is amazing how they still hold up this shop.\n",
    "roof" : "The large tin panel blocks out the rain and weather.\n",
    "counter" : "It has definitely seen better days.\n",
    "display case" : "Watch out!  The glass may cut you.\n",
    "items" : "Type list to see the merchandise in detail.\n",
  ]) );
  set("exits", ([
    "west" : ROOMS+ "road00",
  ]) );
  storeroom = clone_object(STORAGE);
  ob = clone_object("/obj/shield");
  ob->move(storeroom);
  ob2 = clone_object("obj/bandages");
  ob2->move(storeroom);
}
