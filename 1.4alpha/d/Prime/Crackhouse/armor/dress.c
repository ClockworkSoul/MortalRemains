// QC Passed - Cyanide

#include <where.h>
inherit ARMOR;

void create() {
    seteuid(getuid());
    set("author","cattt");
    set("id", ({ "dress", "ugly dress" }) );
    set("short", "an ugly dress");
    set("long", "It is a scary red dress. \n");
    set("value", 10);
    set_armor_type("clothing");
}
