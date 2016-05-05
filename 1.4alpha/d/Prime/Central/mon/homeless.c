#include <mudlib.h>
#include <central.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    set("short", "a homeless man");
    set("long", @Endtext
He is a homeless man who is down on his luck.  He wanders around
the town, trying to find something to eat or get a free handout.
The clothes on his back are torn and tattered.  A strong putrid
odor surrounds this man.
Endtext
    );
    set("id", ({ "man", "homeless man" }) );
    set_name ("man");
    set_living_name("man");
    enable_commands();
    set("attrib1", "lonely");
    set("attrib2", "pathetic");
    set("smell", "He smell disgusting!");
    set("gender", "male");
    set("race", "human");
    set("damage", ({ 1,4 }) );
    set("weapon_name", "fists");
    set("stat/strength", 13);
    set("stat/dexterity", 13);
    set_skill ("attack", 13, "strength");
    set_skill ("defense", 13, "dexterity");
    set_verbs( ({ "swipe at" , "swing at", "jab at" }) );
    set_verbs2( ({ "swipes at", "swings at", "jabs at" }) );
    set("chat_chance", 10);
    set("chat_output", ({
      "Man says: Can you help me out please?\n",
      "Man mumbles something to himself.\n"
    }));
    set("att_chat_output", ({
      "Man shouts at you.\n",
      "Man says: What is your problem!?!\n",
      "Man bites at you with his rotten teeth.\n",
    }));
    set("wealth", 3);
    wear(M_OBJ+"rags", "rags");
    set_level(2);
}
