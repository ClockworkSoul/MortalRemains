// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include <money.h>
#include <move.h>
#include "sigil.h"

// inherit "/std/bank" ;
inherit ROOM;

void create() {
	::create() ;
set("short", "The Hall of Records.");
set("long", @BANK
This is the hall of records, which used to serve as th bank of Sigil.
Now, it's nothing more than a broken doen old shop. The stairs still
lead up, but the bank has been closed.
BANK
);
        set ("light", 1) ;
        set ("exits", ([
	"up" : SIGIL+"bank1.c",
	"north" : SIGIL+"mainst9.c" ]));
}
