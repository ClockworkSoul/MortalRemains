
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a security guard");
    set("long" , "An overweight, lazy security guard. \n"+
      "He usually spends his days watching old \n"+
      "t.v. shows, but now he wants to know what \n"+
      "kind of trouble you are starting. \n");
    set("id" , ({ "guard" , "security" , "security guard" }) );
    set("smell" , "He smells like a big mac. \n");
    set_size(8);
    set_name("security guard");
    set("gender" , "male" );
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set("moving", 1);
    set("speed" , 5);
    set("wealth" , 685);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Guard says: Hey what do you think you're doing? \n",
      "The guard looks at you funny. \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({6,10}) );
    set("weapon_name" , "baton" );
    set ("CLASS", "warrior");
    set_verbs( ({"swing at" , "smack at" , "hit" }) );
    set_level(15);
    arm("/d/Prime/Mall/weap/baton.c");
}

