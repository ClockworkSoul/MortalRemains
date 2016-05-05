#include <mudlib.h>

inherit BUYONLY_SHOP ;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set("objects", ([
     "grok"  :  "/u/a/abyss/town/grok.c",
     "machine"  :  "/u/a/abyss/town/machine.c",
    ]) );
    reset();

    // This defines the stock of the store the first time it's loaded.
    // Every time the store resets, it _might_ start replacing PARTs
    // or adding more to the stock.
    stock = ([
    "stungun" : 10,
    "magnumrev" : 5+random(6),
    "shotgun" : 4+random(3),
    "12mmauto" : 1+random(3),
    "luger" : 10+random(10),
    "axe" : 20,
    "club" : 20,
    "hknife" : 20,
  ]) ;

    set("light", 1) ;
    set("shopkeeper", "grok");
set("shop_dir",  "/d/Prime/Central/weap/");
    set("restock_msg", wrap(
	"A lanky man in a brown UPS jumpsuit enters the shop carrying "+
	"a large cardboard box. He sets the box on the counter, makes "+
	"a note on his pad, and leaves."
      ) );
    set("short", "Grok's Armaments");
    set ("long", wrap(
	"This shop specializes in all manner of weapons and ammunition."+
	" A mind-boggling array of handguns, rifles, shotguns, and even"+
	" daggers and swords assaults your senses."
      )+"\nCommands are: list, buy <item>\n");
    set ("exits", ([
     "north"  :  "/u/a/abyss/town/t10.c"
    ]));
    reset();
}
