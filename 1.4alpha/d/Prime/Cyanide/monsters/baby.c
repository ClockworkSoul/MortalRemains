// baby.c - a baby sea serpent for MAIN+"/underwater.c"
// Remember: cute, but deadly!
// Coded by: Cyanide the Obsidian Enchanter

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid()) ;
    enable_commands ();

    set("author", "Cyanide the Obsidian Enchanter");

    //All the happy stuff concernming identification:
    set("prevent_summon", 1);
    set("short", "a baby sea serpent");
    set("long", "The baby sea serpent, though very young, is still\n"+
      "still a sea serpent after all, and being a growing girl,\n"+
      "is ravenously hungry. Be wary, adventurer!\n");
    set("id", ({ "serpent", "sea serpent", "baby", "monster" }) );
    set_name("the baby sea serpent");
    set_living_name("baby");
    set("gender", "female");
    set("race", "sea serpent");

    //Mass and all related stats:
    set_size(30);

    //Just about everything related to combat:
    set("killer", 1);
    set("aggessive", 9);
    set("armor_class", 3);
    set("damage", ({ 10,30 }) );
    set("natt",2);
    set("weapon_name", "razor-sharp teeth") ;
    set_verbs( ({ "snap at", "bite", "chew on" }) ) ;
    set("forgetful", 0);
    set("wimpy", 0);

    //Stats + skills:
    set("stat/strength", 50);
    set("stat/dexterity", 30);
    set_skill("Natural weapons", 40, "strength");

    //Chats and stuff:
    set("chat_chance", 25);
    set("chat_output", ({
      "The baby sea serpent swims around merrily.\n",
      "The baby sea serpent doesn't seem to notice you...\n",
      "The baby sea serpent's stomach rumbles noisily.\n",
    }) );
    set("att_chat_output", ({
      "The baby sea serpent roars in rage!\n",
      "The baby sea serpent wraps its coils around you!\n",
      "The sea serpent lunges at you hungrily.\n",
    }) );

    //Movement and whatnot:
    set("pursuing", 0);

    set_level(35);
}

void init () {
    ::init();
    add_action ("not", "dive") ;
    add_action ("not", "get");
    add_action ("not", "take") ;
}

int not (string str) {
    write (
      "The baby sea serpent moves to block you, keeping you from\n"+
      "completing your actions!\n");
    return 1 ;
}
