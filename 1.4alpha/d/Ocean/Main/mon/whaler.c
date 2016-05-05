

#include <mudlib.h>
#include "ocean.h";
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a whaler");
    set("long" , wrap(
	"An illegal whaler. He's here looking for some whales to kill. "+
	"His clothes are wet, and he is water-logged, "+
	"but still he goes on. "
      ) );
    set("id" , ({"whaler" , "man" , "poacher"}) );
    set("smell" , "He smells damp. \n");
    set_size(6);
    set_name("the whaler");
    set("gender" , "male" );
    set("race" , "orc");
    set_align("le");
    enable_commands() ;
    set("moving", 1);
    set("speed" , 5);
    set("wealth" , 520);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({6,10}) );
    set("weapon_name" , "spear");
    set ("CLASS", "warrior");
    set_verbs( ({"swing at" , "smack at" , "hit" }) );
    set_level(random(17)+2);
    arm(O_WEAP+"spear.c");
}

