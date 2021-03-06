
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a teenaged girl");
    set("long" , "A teenaged girl who spends all her time \n"+
      "at the mall. She never has any money to buy anything, \n"+
      "but she is always here. \n");
    set("id", ({"teen","girl" , "teenager" , "teenaged girl" }) );
    set("smell" , "She smells like bubblegum. \n");
    set_size(5);
    set_name("teenaged girl");
    set ("gender", "female") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set("wealth" , 250);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({2,5}) );
    set("weapon_name", "hairbrush");
    set ("CLASS", "warrior");
    set_verbs( ({"swing at" , "hit" , "smack at" }) );
    arm("/d/Prime/Mall/weap/hairbrush.c");
    set_level(6);

}
