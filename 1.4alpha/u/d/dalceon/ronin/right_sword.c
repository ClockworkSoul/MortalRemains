
#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;
inherit "/u/d/dalceon/ronin/wildbonus.c";

int valid_arg(string);
void create() {
    // Don't worry about this, just make sure its there.
    seteuid(getuid());

    // "author" should be set in all objects and rooms you code.
    // It should be a lowercase name - very simple.
    set("author", "dalceon");


    set("name", "sword");

    set_weapon_type("sword/long");

    set_material_type("metal/fine steel");

    set("id", ({ "longsword", "sword", "longsword of wildfire" }) );

    //short is what you see when it's on the floor or in an inventory
    // Make sure any "a" or "an" is lowercased!
    set("short", "The Longsword of Wildfire");

    //long is what ya get when a player examines it
    set("long", @SwordDesc
    An exquisite sword.  The blade is long and slightly curve.
    It was painstakingly crafted years ago from the heat of a
    volcano, using the finest steel.  The hilt is long blue and
    ribbed for grip. Its half of the Twin Swords of Wildfire. It
    has to be wielded in the right hand for full power. When the 
    swords are joined, they form the Sword of Wildfire. 
SwordDesc
    );
        set("damage", ({1,15}));
    set("nosecond", 0);
    set("wield_func", "add_bonus");
    set("unwield_func", "remove_bonus");
}

void init() {
   add_action("join_swords", "join");
}

int join_swords(string arg) {

   object left_sword;
   object dbl_sword;
   left_sword = present("shortsword of wildfire",this_player());

   if(!arg || !valid_arg(arg))
      return 0;

   else if(!left_sword) {
      write("You need the Shortsword of Wildfire to join.\n");
      return 1;
   }
   else {
      write("You join the two swords of Wildfire to form a new weapon!!.\n");
      write("Your body tingles as a new power pulses through your body.\n");
      say(TP->query("cap_name")+" joins the two swords to form a new weapon!.\n");
      say(TP->query("cap_name")+"'s body pulses with an intense light.\n");
      dbl_sword = clone_object("/u/d/dalceon/ronin/wild_sword.c");
      dbl_sword->move(this_player());
      destruct(left_sword);
      destruct(this_object());
      return 1;
   }
}

int valid_arg( string arg ) {
    if((arg != "swords") && (arg != "longsword and shortsword"))
       return 0;
    return 1;
}
