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
    set("short", "Gloves of Wildfire");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @GloveDesc

The Gloves of Wildfire, are a perfect match for the Armour of Wildfire.
They also glow the same bright red.  They cover the entire forearm, and
contain three spikes at the end for added defence and protection. There
is also a giant spike flaring out from each elbow.
GloveDesc
    );

    //this allows a player to exa the item in more ways than 1
    set("id", ({ "gloves", "wildfire gloves", "gloves of wildfire"}) );
    set("armor",1);
    set("value",200);
    set("material_type", "metal/fine steel");
    set("equip_func", "add_bonus");
    set("unequip_func", "remove_bonus");

    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
    set_armor_type("gloves");
}
