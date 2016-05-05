// TROLL_CHEST.C

#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

#define MMAIN "."

void create() {

    object ob1,ob2;

    ::create() ;
    seteuid(getuid());
    set("short", "a soggy chest");
    set("id", ({ "chest" }));
    // Containers have two long descriptions, one for open and one for closed.
    set_closed_long("A soggy but sturdy chest. Its lid is closed.\n") ;
    set_open_long("A treasure chest with its lid wide open.\n") ;
    // Some containers are closeable: others are not. This controls it.
    set_possible_to_close(1) ;
    set ("bulk", 250) ;
    set ("mass", 200) ;
    // Capacity is the total amount of mass than can be put in the bag, and
    // volume is the total amount of bulk that can be put in.
    set ("capacity", 1000) ;
    set ("volume", 225) ;
    set ("value", ([ "gold":0 ]) ) ;
    //
    // Now that we have set how big it is.....Lets put something in it!
    /*  This will add an object.
      ob1 =  clone_object(MMAIN+"/simon_ring.c");
      ob1 -> move(this_object());
    */
    ob2 =  clone_object("/std/coins");
    ob2 -> set_number(random(50)+50) ;
    ob2 -> move(this_object());

    // Each lock has a number which controls how much work is needed to fully
    // lock it, and each key has a number which controls how much locking that
    // key does in one command. "max_lock" is the total amount of locking that
    // can be spent on this lock before it is fully locked.
    // Usually the key has enough efficiency that the key can fully lock the
    // lock with one command. But it doesn't have to be that way if you'd
    // rather it wasn't.
    set("max_lock", 30);
    // If lock=0, the object has no lock. If lock<0, it has a lock but is unlocked.
    // If lock>0, the lock is locked to that degree of effort. Not to be greater
    // than max_lock.
    set("lock", 30);
    // The ident string of the key which opens the lock.
    set("key", "rus_key");
    // default position for a chest is open...Toggle closes it.
    this_object() -> toggle_closed();
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
    container::init() ;
    lock::init() ;
}
