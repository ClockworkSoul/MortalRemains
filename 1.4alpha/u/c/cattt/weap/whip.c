#include <mudlib.h> 
#include <where.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "cattt");
    set("name", "whip");
    set("id", ({ "whip", "leather whip" }) );
    set("short", "a leather whip");
    set("long", 
      "A leather whip used to invoke pleasure and pain.\n");

    set("size", -1);

    set("type","slashing");
    set_weapon_type("whip");
    set("nosecond",0);
    set("value", 5);
    set("damage",({ 2, 5 }) );
}
