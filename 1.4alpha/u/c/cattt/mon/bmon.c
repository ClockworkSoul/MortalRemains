#include <mudlib.h>
#include <where.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "Bmon");
    set("long", @Endtext
This creature must have grown from the toxins that plaque this room.
It looks like it was once a small mammal but now it is huge!  It's
large eyes follow your movement as if you were it's prey.
Endtext
    );
    set("id", ({ "Bmon", "bmon", "creature" , "monster" }) );
    set_name ("Bmon");
    enable_commands();
    set("race", "monster");
    set("spell_points", 300);
    set("max_sp", 300);
    set("armor_class", -2);
    set("aggressive", 1); 
    set("damage", ({ 3,6 }) );
    set("weapon_name", "claws");
   set("damage_type", "slashing");
    set("stat/strength", 15);
    set("stat/dexterity", 18);
    set_verbs( ({ "scratch at" , "claw at" }) );
    set_verbs2( ({ "scratches at", "claws at" }) );
    set("chat_chance", 3);
    set("chat_output", ({
      "Bmon growls under it's breathe giving you the chills. \n",
      "Bmon spies at you from a dark corner.\n",
    }));
    set("att_chat_output", ({
      "Bmon's tail swings at you. \n",
    }));
    set_size(15);
    set_level(15);
}
