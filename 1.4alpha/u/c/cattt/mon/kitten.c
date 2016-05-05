#include <mudlib.h>
#include <where.h>

inherit MONSTER;
object kittycollar;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "a lil kitten");
    set("long", @Endtext
The small kitten just naps on your lap happily.
Endtext
    );
    set("id", ({ "small kitten", "lil kitten" , "kitten", "kitty" }) );
    set_name ("kitten");
    enable_commands();
    set("gender", "female");
    set("race", "feline");
    set("armor_class", 9);
    set("damage", ({ 1,3 }) );
    set("weapon_name", "claws");
    set("stat/strength", 8);
    set("stat/dexterity", 8);
    set_verbs( ({ "bite at" }) );
    set_verbs2( ({ "bitess at" }) );
    set("chat_chance", 2);
    set("chat_output", ({
      "The little kitten purrs while napping. \n",
                      }));
    set("att_chat_output", ({
      "The kitten cowers in fear.\n",
       }));
    wear(M_ARM+"kittycollar.c","kittycollar");
    set_size(2);
    set_level(2);
}
