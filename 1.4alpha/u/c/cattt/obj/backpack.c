// Barfboy's wearable container.
// Givin to Cattt to hack and use  :)

#include <mudlib.h>
#include <sewers.h>

inherit "/u/c/cattt/wearbag.c";
void create(){
    seteuid(getuid());
    ::create();
    set("id", ({ "pack", "backpack", "back pack" }));
    set("short", "a back pack");
    set_open_long("This is a large back pack.  It looks like it could hold alot.\nIt is currently open.\n");
    set_closed_long("This is a large back pack.  It looks like it could hold alot.\nIt is currently closed.\n");
    set("capacity", 5000);
    set("max_cap", 5000);
    set("volume", 5000);
    set("max_vol", 5000);
    set("armor", 4);
    set("type", "cloak");
    set("value", ({ 300, "gold" }));
    set ("mass", 1);
    set ("bulk", 1);
    set_possible_to_close(1);
}
void init(){
    wearbag::init();
}
