/*
** File: wcabinet.c
**Author: Lady Nsd
*/

#include <mudlib.h>

inherit CONTAINER ;

object b1, b2, b3, b4, b5, b6;
void create() {
    ::create() ;
    set("author", "nsd");
    set("short", "a wall cabinet");
    set("id", ({ "cabinet", "wall cabinet"}) );
    set_closed_long("A wall cabinet. It's doors are closed.\n") ;
    set_open_long("A wall cabinet. It's open\n") ;
    set_possible_to_close(1) ;

    set("mass", 1000);
    set ("capacity", 2000);
    set ("volume",1000);
    set("max_lock", 0);
    set("prevent_clean", 1);
    set("lock",0);

    toggle_closed();
    b1 = clone_object("/u/n/nsd/private/towel.c");
    b1->move(this_object());
    b2 = clone_object("/u/n/nsd/private/towel.c");
    b2->move(this_object());

    b3 = clone_object("/u/n/nsd/private/toothbrush.c");
    b3->move(this_object());
    b4 = clone_object("/u/n/nsd/private/toothbrush.c");
    b4->move(this_object());

    b5 = clone_object("/u/n/nsd/private/soap.c");
    b5->move(this_object());

    b6 = clone_object("/u/n/nsd/private/mouthwash.c");
    b6->move(this_object());
}
void init() {
    container::init() ;
}

