#include <mudlib.h>
#include <where.h>

inherit ARMOR;

void create() {
  set("author","cattt");
  set("id", ({ "collar", "dog collar" }) );
  set("short", "a large dog's collar");
  set("long", @Endtext
This large dog collar has metal spikes along it.  A steel plate is
bolted to it which reads: "Killer".  From the looks of it you realize
this probabbly wasn't easily obtained.  
Endtext
);
  set("value", ({ 9, "silver" }) );
  set_armor_type("amulet");
}
