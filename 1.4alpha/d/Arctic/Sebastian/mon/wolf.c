/*
	File: wolf.c, duh, otherwise, you're dreaming this, crackhead.
	Desc: A timber wolf, aww how cute!
	Date: June 24, booooriinnngg...I hate comments
	Other Stuff: Um, Ham and Cheese?
*/
#include <mudlib.h>
object pelt;
inherit MONSTER;
void create(){
    ::create();
    set("author", "sebastian");
    set("short", "a timber wolf");
    set("long", @EndText
You see a beautiful, sleek timber wolf.  It's fur shines in the light.
It is calm and peaceful, keeping to itself.  It's pelt is worth a pretty
penny....
EndText
    );
    set("id", ({"wolf","timber wolf","dog", "timberwolf"}));
    set_size(6);
    set_name("timber wolf");
    set("gender", "neuter");
    set("race","wolf");
    set("damage", ({1,5}));
    set("weapon_name", "fangs");
    set("natt", 3);
    set_verbs(({"bite","gnash","tear at"}));
    set_verbs2(({"bites","gnashes","tears at"}));
    enable_commands();
    set("chat_chance", 4);
    set("chat_output", ({"the wolf sniffs the air.\n", 
      "the wolf looks to the moon and howls.\n",
      "the wolf looks at you with piercing blue eyes.\n"}));
    set("att_chat_output", "The wolf growls angrily.\n");
    set("stat/dexterity", 18);
    pelt = clone_object("/u/s/sebastian/items/wpelt.c");
    pelt->move(this_object());
    set_level(3);
}
