#include <mudlib.h>
#include <where.h>

inherit ARMOR;

void create() {
  set("author","cattt");
  set("id", ({ "pimp's robe", "robe" }) );
  set("short", "a pimp's robe");
  set("long", @Endtext
A rich and bright purple robe. A large lapel makes this robe
stand out even more.  The pockets run deep and look able to
carry a few odds and ends.
Endtext
);
  set("value", ({ 10, "silver" }) );
  set_armor_type("cloak");
}
