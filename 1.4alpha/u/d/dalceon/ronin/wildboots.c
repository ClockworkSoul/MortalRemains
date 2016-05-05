/*  File: armor.c
**  Purpose: You figure it out, duh...
**  Date: July 30th, 1997
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
*/


inherit "/u/d/dalceon/ronin/wildbonus.c";
inherit ARMOR;

void create() {
    //short is what you see w/o an examine
    set("short", "Boots of Wildfire");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @BootsDesc
The The Boots of Wildfire are massive.  The are knee length boots
that glow a fiery red.  The boots are squared off, with what appears
to be a metal stirrup in the back.
BootsDesc
    );

    //this allows a player to exa the item in more ways than 1
    set("armour",1);
    set("material_type", "metal/fine steel");
    set("value",200);
    set("id", ({ "boots", "wildfire boots" }) );
    set("equip_func", "add_bonus");
    set("unequip_func", "remove_bonus");


    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
    set_armor_type("boots");
}
