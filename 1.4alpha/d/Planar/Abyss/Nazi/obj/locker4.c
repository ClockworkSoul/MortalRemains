//locker4.c
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
set("id", ({ "004" }) );
    // Containers have two long descriptions, one for open and one for closed.
set_closed_long("This is locker #004. It's closed.\n") ;
set_open_long("This locker is open.\n");
    // Some containers are closeable: others are not. This controls it.
    set_possible_to_close(1) ;

set("mass", 1000);
    // Capacity is the total amount of mass than can be put in the bag, and
    // volume is the total amount of bulk that can be put in.
    set ("capacity", 1000) ;
set("volume", 1000);
    // Each lock has a number which controls how much work is needed to fully
    // lock it, and each key has a number which controls how much locking that
    // key does in one command. "max_lock" is the total amount of locking that
    // can be spent on this lock before it is fully locked.
    // Usually the key has enough efficiency that the key can fully lock the
    // lock with one command. But it doesn't have to be that way if you'd
    // rather it wasn't.
    set("max_lock", 10);
    // If lock=0, the object has no lock. If lock<0, it has a lock but is unlocked.
    // If lock>0, the lock is locked to that degree of effort. Not to be greater
    // than max_lock.
set("lock", 1);
    // The ident string of the key which opens the lock.
set("key", "sauna key 004");

    toggle_closed();
ob1 = clone_object(NAZI_OBJ+"towel.c");
ob1->move(this_object());
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
    container::init() ;
    lock::init() ;
}
