/*
** File: axe.c
** Date: June somthing (leave me alone, I am tired)
** Purpose: Axes are used for a lot of things, figure one out.
** Other Notes: I like camels.
**
** This is an example of a long comment.
*/

// This is an example of a short comment.

#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
// Don't worry about this, just make sure its there.
  seteuid(getuid());

// "author" dosen't have to be set, but it's a good habit
// It should be a lowercase name - very simple.
   set("author", "nightmask");

// "name" makes it an axe, and not "0"
   set("name", "axe");

// This makes it what it is, the other types can be found in
// the dir /doc/properties
   set_weapon_type("axe/hand");

// The material type can be anything, the default usually steel or
// wood
   set_material_type("metal/silver");

// The "id" is all the things you can call it.
   set("id", ({ "axe", "silver axe" }) );

//short is what you see when it's on the floor or in an inventory
// Make sure any "a" or "an" is lowercased!
   set("short", "an axe");

//long is what ya get when a player examines it
   set("long", "This is a finely crafted silver axe.\n"+
       "The handle is made of wood, but the blades are pure silver.\n");

// bonus makes it a magical weapon, 1,2,3,4,5
// You can also do it like this set_bonus(1,1,1);
//   The first number makes it a +1 weapon
//   The second means it has a +1 to hit
//   The third means it has a +1 to damage
// In other words it is conceieveable that you could make a weapon
// that would have a +1 to hit and damage, but not be magical
// You would do that like this       set_bonus(0,1,1);
   set_bonus(1);

// "nosecond" set to 1 makes it a 2 handed weapon, 0 means you can have 
// another weapon wielded with it
   set("nosecond", 0);

//verbs are what you see when you attack. They are optional.
   set_verbs( ({ "slice", "slash", "cut into" }) );
//verbs2 is what the other players in the room see
   set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
