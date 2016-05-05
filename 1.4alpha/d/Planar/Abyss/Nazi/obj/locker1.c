//locker1.c
//one of many lockers in here...
//Nsd march 3, 2000

#include <mudlib.h>
#include "nazi.h"

inherit CONTAINER ;
inherit LOCK ;

object ob1;
void create() {
    ::create() ;
    set("author", "nsd");
    set("short", "Locker");
    set("id", ({"001"}) );
    set_closed_long("This is locker #001. It's closed.\n") ;
    set_open_long("This locker is open.\n");
    set_possible_to_close(1) ;
    set("prevent_get", 1);   // Now it can't be picked up.
    set("mass", 10000);   // It's a heavy locker, now
    set("capacity", 1000);
    set("max_lock", 10);
    set("lock", 1);
    set("key", "sauna key 001");

    toggle_closed();
    ob1 = clone_object(NAZI_OBJ+"towel.c");
    ob1->move(this_object() );
}

void init() {
    container::init() ;
    lock::init() ;
}
