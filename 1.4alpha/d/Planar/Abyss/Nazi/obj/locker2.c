//locker2.c
//one of many lockers in here...
//Nsd march 3, 2000

#include <mudlib.h>
#include "nazi.h"

inherit CONTAINER ;
inherit LOCK ;

object ob1;

void create() {
    ::create() ;
set("short", "Locker");
set("id", ({ "002" }) );
    // Containers have two long descriptions, one for open and one for closed.
set_closed_long("This is locker #002. It's closed.\n") ;
set_open_long("This locker is open.\n");
    // Some containers are closeable: others are not. This controls it.
    set_possible_to_close(1) ;

    set("max_lock", 10);
    // If lock=0, the object has no lock. If lock<0, it has a lock but is unlocked.
    // If lock>0, the lock is locked to that degree of effort. Not to be greater
    // than max_lock.
set("lock", 1);
    // The ident string of the key which opens the lock.
set("key", "sauna key 002");
set("mass", 1000);

    toggle_closed();
ob1 = clone_object(NAZI_OBJ+"towel.c");
ob1->move(this_object() );
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
    container::init() ;
    lock::init() ;
}
