#include <mudlib.h>
#include <where.h>

inherit OBJECT;

void create() {
    set ("to_lock", "dirty_key");
    set ("name", "dirty_key");
    set ("long", "A small, old, dirty key.\n");
    set ("short", "a small dirty key");
    set ("id", ({ "key", "dirty key", "small key" }));
    set("lock_turn", 30);
    set("value", 5);
}
