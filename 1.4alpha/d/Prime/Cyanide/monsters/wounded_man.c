#include <mudlib.h>
#include "monsters.h"

// wounded_man.c - the guy who sits and warns people how
// Horrible the dark area is.
// Coded by: Cyanide the Obsidian Enchanter

inherit MONSTER ;

void create () {
    object ob;
    ::create();
    seteuid(getuid()) ;
    enable_commands ();

    set("author", "cyanide");

    //All the happy stuff concernming identification:
    set("prevent_summon", 1);
    set("short", "a mortally wounded knight");
    set("long", @ENDLONG
The knight is apparently somewhere around the age of 40, and grey
hair adorns his temples. His face is a mask of excruciating pain, 
and his once ornate armor has been rended and torn by obviously large
claws and is covered with blood.
ENDLONG
    );
    set("id", ({ "man", "knight", "warrior" }) );
    set_name("the mortally wounded nobleman");
    set("gender", "male");
    set_living_name("knight1");
    set ("race", "human");

    //Mass and all related stats:

    //Just about everything related to combat:
    set ("no_attack", 1);
    set("agressive", 0);
    set("hit_points", 1);
    set("attack_strength", 18);
    set("damage", ({ 10,30 }) );
    set("natt",2);
    set("weapon_name", "fists");
    set_verbs( ({ "snap at", "bite", "chew on" }) ) ;
    set("forgetful", 0);
    set("wimpy", 0);

    //Stats + skills:
    set("stat/strength", 25);
    set("stat/dexterity", 13);
    set_skill("Natural weapons", 18, "strength");

    //Chats and stuff:
    set("chat_chance", 35);
    set("chat_output", ({
      "The wounded knight groans in pain.\n",
      "The Knight says: Don't go on! It's hopeless!\n",
      "The wounded knight sobs hopelessly.\n",
      "The wounded knight attempts to move, but fails miserably.\n",
      "The Knight says: Beware the crevasse! Great evil lurks!\n",
      "The Knight says: If only that sea demon didn't "+
      "guard that ring!\n",
      "The noble knight lapses into unconsciousness for a moment.\n",
      "The Knight says: All I did was touch the mirror!\n",
      "The Knight warns: Go back! Try the newbie area instead!\n",
      "The Knight mumbles something about other players attacking him.\n",
      "The Knight curses the name of Cyanide.\n",
      "The Knight tells you: His apprentice, Gothmog, is almost"+
      " as bad, if not worse!\n",
      "The Knight shouts: My squire pressed the button on the"+
      " machine, and just dissapeared!\n",
      "The Knight says, frantically: Beware the balrog! He "+
      "will slay thee!\n",
    }) );

    set("att_chat_output", ({
      "The Knight fights bravely on.\n",
    }) );

    //Movement and whatnot:
    set("pursuing", 0);
    set("moving", 0);
    set("speed", 6);

    //Weapons and Armor:
    ob = clone_object(OBJ+"/kn_sword.c");
    ob->move(TO);
    wear(OBJ+"/kn_armor.c", "armor");
    wear(OBJ+"/kn_shield.c", "shield");

    set_level(12);
    set("hit_points", 1);
}

void init () {
    ::init();
    command("wield sword");
    add_action ("not", "meditate");
    add_action ("not", "invoke");
    add_action ("not", "chant");
    add_action ("not", "cast");
}

int not (string str) {
    write (
      "The knight stops you.\n"+"\n"+
      "The Knight says: I will have none of that in my presence!\n");
    return 1 ;
}
