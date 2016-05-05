#include <messages.h>
#include <mudlib.h>
#include "central.h"

inherit BUYONLY_SHOP ;

int restocked = 0;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set("objects", ([
      "grik" : M_MON + "grik.c",
      "machine" : M_OBJ+"ammovender.c",
    ]) );
    reset();

    // This defines the stock of the store the first time it's loaded.
    // Every time the store resets, it _might_ start replacing PARTs
    // or adding more to the stock.
    stock = ([
    "m_ceska" : random(3),
    "m_msheadhntr" : random(2),
    "stungun" : 10,
    "magnumrev" : 5+random(6),
    "shotgun" : 4+random(3),
    "12mmauto" : 1+random(3),
    "luger" : 10+random(10),
    "2hsword" : random(3),
    "longsword" : 4+random(10),
    "shortsword" : 6+random(11),
    "axe" : 20,
    "club" : 20,
    "hknife" : 20,
  ]) ;

    set("light", 1) ;
    set("shopkeeper", "grik");
    set("shop_dir", M_WEAP);
    set("restock_msg", wrap(
	"A lanky man in a brown UPS jumpsuit enters the shop carrying "+
	"a large cardboard box. He sets the box on the counter, makes "+
	"a note on his pad, and leaves."
      ) );
    set("short", "Grik's Armaments");
    set ("long", wrap(
	"This shop specializes in all manner of weapons and ammunition."+
	" A mind-boggling array of handguns, rifles, shotguns, and even"+
	" daggers and swords assaults your senses."
	"\nA set of stairs leads downstairs to the Gun Club"
      )+"\nCommands are: list, buy <item>\n");
    set ("exits", ([
      "east" : M_ROOM+"road0_-4.c",
      "down" : "/d/class/warrior/Sharpshooter/room/SS_guild.c"
    ]));
    reset();
}

void reset() {
    object machine;

    restocked++;

    machine = present("machine", TO);
    ::reset();
    if (machine && restocked>=3) {
	restocked = 0;
	message(MSG_INFO, "Grik restocks the ammo machine.\n",
	  all_inventory(TO) );
	machine->clean();
    }
}

/* EOF */
