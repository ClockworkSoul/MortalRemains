

#include <mudlib.h>
inherit MONSTER ;

int dad_flag;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "a whiny bratty kid");
    set("long" , "This is a spoiled little kid who is \n"+
      "whining and crying because she can't have \n"+
      "her way. If I were you, I think I would slap her. \n");
    set("id" , ({"kid" , "brat" , "whiny kid" , "bratty kid" }) );
    set("smell" , "She smells sticky. \n");
    set_size(3);
    dad_flag = 1;
    set_name("rotten kid");
    set ("gender", "female") ;
    set("race" , "half-orc");
    set_align("le");
    enable_commands() ;
    set("wealth" , 25);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({1,2}) );
    set("weapon_name" , "barbie doll");
    set_verbs( ({"swing at" , "hit" , "smack at" }) );
    set_level(5);
}

void init() {
    add_action("slap_kid" , "slap");

}
int slap_kid (string str) {
    object dad;
    dad = clone_object("/d/Prime/Mall/mons/dad.c");
    if(dad && dad_flag) {
	say(TPN+" slaps the kid whose dad comes running... pissed!\n");
	write(@EndText
You slap the bratty kid across the face.
Suddenly you realize what a mistake you made
as her father comes running. He looks pissed!
EndText);

	dad->move( environment(this_player() ) );
	dad->kill_ob( this_player() );
	dad_flag = 0;
    }else
	write("You rear back to slap the kid... but then think better of it. \n");
    return 1;
}
