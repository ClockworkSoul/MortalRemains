//skey2.c
//Opens lockers
//Nsd  march 3, 2000

#include <mudlib.h>

inherit OBJECT;

create() {
set("to_lock", "sauna key 002") ;
set("name", "sauna key 002");
set("long", "A key that opens only lockers.\n");
set("short", "sauna key 002");
set("id", ({ "key", "sauna key", "key 002" }));
    set("lock_turn", 10);
}
