//locker9.c
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
set("id", ({ "009" }) );
set_closed_long("This is locker #009. It's closed.\n") ;
set_open_long("This locker is open.\n");
    set_possible_to_close(1) ;

set("mass", 1000);
    set ("capacity", 1000) ;
set("volume", 1000);
    set("max_lock", 10);
set("lock", 1);
set("key", "sauna key 009");

    toggle_closed();
ob1 = clone_object(NAZI_OBJ+"towel.c");
ob1->move(this_object() );
}

void init() {
    container::init() ;
    lock::init() ;
}
