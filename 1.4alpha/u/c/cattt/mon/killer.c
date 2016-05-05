#include <mudlib.h>
#include <where.h>

inherit MONSTER;
object collar;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "Killer");
    set("long", @Endtext
An extremely large dog, probabbly a Great Dane/Rottweiler mix. It growls
at you menacingly.  He is chained by the door as a guard.  He stands over
a lot of bones, which from the looks of it, seem human.
Endtext
    );
    set("id", ({ "Killer", "killer", "dog" }) );
    set_name ("Killer");
    enable_commands();
    set("gender", "male");
    set("race", "dog");
    set("armor_class", 8);
    set("aggressive", 0); 
    set("damage", ({ 1,3 }) );
    set("weapon_name", "teeth");
    set("stat/strength", 15);
    set("stat/dexterity", 12);
    set_verbs( ({ "bite at" }) );
    set_verbs2( ({ "bitess at" }) );
    set("chat_chance", 2);
    set("chat_output", ({
      "The large dog growls and barks loudly at you. \n",
      "Killer stares at you and paces on his chain.\n",
                      }));
    set("att_chat_output", ({
      "The dog does it's best to gaurd the door by attacking you.\n",
       }));
    wear(M_ARM+"collar.c","collar");
    set_size(5);
    set_level(13);
}
