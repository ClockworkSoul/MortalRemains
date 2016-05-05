#include <mudlib.h>
#include <where.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {

    object ob1,ob2;

    ::create() ;
    seteuid(getuid());
    set("short", "a chest");
    set("id", ({ "chest" }));
    set_closed_long("A tattered and worn chest. Its lid is closed.\n") ;
    set_open_long("An old chest with its lid wide open.\n") ;
    set_possible_to_close(1) ;
    set ("bulk", 250) ;
    set ("mass", 200) ;
    set ("capacity", 1000) ;
    set ("volume", 225) ;
    set ("value", ([ "gold":0 ]) ) ;

    ob1 =  clone_object(M_OBJ+"syringe.c");
    ob1 -> move(this_object());
    ob2 = clone_object("/std/coins.c");
    ob2 -> set_number(101);
    ob2 -> move(this_object());

    set("max_lock", 30);
    set("lock", 10);
    set("key", "dirty_key") ;
    this_object() -> toggle_closed();
}

void init() {
    container::init() ;
    lock::init() ;
}
