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
    set("short", "Helmet of Wildfire");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @HelmDesc
The Helmet of Wildfire is a viscious looking ornament. Its look
strikes fear into the soul of any opponent.  It glows a fiery red.
Large curved blades blast from each side of the temple.  The face
mask looks like a metal skull. With a thin metal mohawk running
down the center of the skull, you know this helmet means business.
The helmet helps add power to the wildfire suit.
HelmDesc
    );

    //this allows a player to exa the item in more ways than 1
    set("id", ({ "helmet", "helm", "wildfire helmet"}) );
    set("armor", 1);
    set("material_type", "metal/fine steel");
    set("value", 200);
    set("equip_func", "add_bonus");
    set("unequip_func", "remove_bonus");

    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
    set_armor_type("helmet");
}
