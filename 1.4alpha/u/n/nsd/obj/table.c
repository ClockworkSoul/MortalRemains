//table.c
//A bedside table.
//Nsd march 3, 2000

#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

object t1, t2, t3, t4, t5, t6, t7, t8;
void create() {
    ::create() ;
    set("author", "nsd");
    set("short", "a bedside table");
    set("id", ({ "table", "drawer" }) );
    set_closed_long("A bedside table. It's drawer is closed.\n") ;
    set_open_long("A bedside table with an open drawer.\n" );
    set_possible_to_close(1) ;

    set("mass", 1000);
    set ("capacity", 2000);
    set ("volume", 500);
    set("max_lock", 10);
    set("prevent_clean", 1);
    set("lock", 1);
    set("key", "rose key") ;

    toggle_closed();
    t1 = clone_object("/u/n/nsd/private/package.c");
    t1->move(this_object());

    t2 = clone_object("/u/n/nsd/private/oil2.c");
    t2->move(this_object());

    t3 = clone_object("/u/n/nsd/private/strbasket.c");
    t3->move(this_object());

    t4 = clone_object("/u/n/nsd/private/wine.c");
    t4->move(this_object());

    t5 = clone_object("/u/n/nsd/private/glass.c");
    t5->move(this_object() );

    t6 = clone_object("/u/n/nsd/private/glass.c");
    t6->move(this_object() );

    t7 = clone_object("/u/n/nsd/private/chocolate.c");
    t7->move(this_object() );

    t8 = clone_object("/u/n/nsd/private/wpcream.c");
    t8->move(this_object() );
}
void init() {
    container::init() ;
    lock::init() ;
}

