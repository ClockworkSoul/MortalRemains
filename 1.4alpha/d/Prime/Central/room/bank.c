// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include "central.h"
#include <money.h>
#include <move.h>

inherit "/std/bank" ;

void create() {
    ::create();
    set ("short", "Bank of "+MUD_NAME+", "+CITY_NAME+" Branch") ;
    set("long", wrap(
	"Welcome to the "+query("short")+"! Here you may open an account, "+
	"and store your extra credits, just in case. There is a small sign "+
	"on the cashier's counter."
      ) );
    set ("light", 1) ;
    set ("exits", ([
      "south" : M_ROOM+"road2_0.c",
    ]) );
    set ("item_desc", ([
      "sign" : sign(),
    ]) );
}


