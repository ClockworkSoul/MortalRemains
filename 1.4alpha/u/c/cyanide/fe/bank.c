// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include <money.h>
#include <move.h>
#include <path.h>

inherit "/std/bank" ;
inherit DOORS;

void create() {
    ::create() ;
    set ("short", "Bank of Vieillere");
    set ("long", @Endtext
Welcome to the Vieillere Bank.  Here, you can stash your money away so
you can get more, or protect your hard earned money.  For a modest fee of
25 gold, you can <open> an account and acquire a bank card.  With a card,
you can <deposit> and <withdraw> your money.
Endtext
    );
    set ("light", 1) ;
    set("objects", ([ "drone" : MOBS + "sec_drone" ]) );
    set ("exits", ([
      "east" : ROOMS+"road18" 
    ]) );
    create_door("east", "west", "A solid metal door", "open");
    reset();
}
