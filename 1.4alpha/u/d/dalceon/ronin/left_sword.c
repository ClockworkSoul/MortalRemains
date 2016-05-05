
#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit "/u/d/dalceon/ronin/wildbonus.c";
inherit WEAPON;

void create() {
    // Don't worry about this, just make sure its there.
    seteuid(getuid());

    // "author" should be set in all objects and rooms you code.
    // It should be a lowercase name - very simple.
    set("author", "dalceon");


    set("name", "sword");

    set_weapon_type("sword/short");

    set_material_type("metal/fine steel");

   set("id", ({ "shortsword", "shortsword of wildfire", "sword" }) );

    //short is what you see when it's on the floor or in an inventory
    // Make sure any "a" or "an" is lowercased!
    set("short", "Shortsword of Wildfire");

    //long is what ya get when a player examines it
    set("long", @SwordDesc
    An exquisite sword.  The blade is short and slightly curved.
    It was painstakingly crafted years ago from the heat of a
    volcano, using the finest steel.  The hilt is long blue and
    ribbed for grip. Its half of the Twin Swords of Wildfire. This
    sword should be wielded in the left hand to get full power. When
    The twin swords are joined, they will form the Sword of Wildfire.
SwordDesc
    );

    set("damage", ({2,10}));
    set("nosecond", 0);
    set("second", 1);
    set("wield_func", "add_bonus");
    set("unwield_func", "remove_bonus");
}
