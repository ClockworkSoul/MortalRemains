#include <mudlib.h>
#include <where.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "a bum passed out");
    set("long", @Endtext
This orc looks to have passed out long ago.  Trash has been
thrown on him making him look even dirtier than he probabbly
looked earlier.  His clothes are torn and obviously old.
Endtext
    );
    set("id", ({ "orc", "bum" }) );
    set_name ("Orc");
    enable_commands();
    set("gender", "male");
    set("race", "orc");
    set("spell_points", 30);
    set("max_sp", 30);
    set("armor_class", 0);
    set("aggressive", 0); 
    set("damage", ({ 1,3 }) );
    set("weapon_name", "fists");
    set("stat/strength", 10);
    set("stat/dexterity", 7);
    set_verbs( ({ "scratch at" , "claw at" }) );
    set_verbs2( ({ "scratches at", "claws at" }) );
    set("chat_chance", 10);
    set("chat_output", ({
      "The orc twitches while unconscious.\n",
    }));
    set("att_chat_output", ({
      "The bum tries to leave but stumbles.\n",
    }));
    set_size(6);
    set_level(8);
}
