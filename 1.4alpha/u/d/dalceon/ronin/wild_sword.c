
#include <mudlib.h>   //This calls all the neat stuff Cy programed
#define PN this_player()->query("cap_name")

inherit WEAPON;
inherit "/u/d/dalceon/ronin/wildbonus.c";

void create() {
    // Don't worry about this, just make sure its there.
    seteuid(getuid());

    // "author" should be set in all objects and rooms you code.
    // It should be a lowercase name - very simple.
    set("author", "dalceon");


    set("name", "sword");

    set_weapon_type("sword/long");

    set_material_type("metal/fine steel");

    set("id", ({ "sword of wildfire", "wildfire sword","sword" }) );

    //short is what you see when it's on the floor or in an inventory
    // Make sure any "a" or "an" is lowercased!
    set("short", "Doublebladed Sword of Wildfire");

    //long is what ya get when a player examines it
    set("long", @SwordDesc
    An incredible sword.  The sword was formed by the joining of the short
    and long Swords of Wildfire. The longsword forms the top, and the
    shortsword points toward the ground.  The two hilts are joined at the
    ends to form a large center grip. The sword is used to help channel the
    energy of the Armour of Wildfire when it flares up. The swords can be
    unassembled.
SwordDesc
    );

    set("nosecond", 1);
    set("wield_func", "add_bonus");
    set("unwield_func", "remove_bonus");
    set("damage", ({5,30}));
    set("value", 3000);

}

void init() {
    add_action("unjoin", "unassemble");
}

int unjoin( string arg) {

    object right;
    object left;
    if((arg == "sword") || (arg == "sword") || (arg == "sword of wildfire")) {
       write("You unassemble the Sword of Wildfire.\n");
       say(PN+" unassembles the Sword of Wildfire.\n");
       right = clone_object("/u/d/dalceon/ronin/right_sword.c");
       left = clone_object("/u/d/dalceon/ronin/left_sword.c");
       if(this_object()->query("wielded"))
       this_object()->unwield(0);
       right->move(this_player());
       left->move(this_player());
       destruct(this_object());
       return 1;
    }
    else {
       write("Unassemble what??");
       return 1;
    }
}

