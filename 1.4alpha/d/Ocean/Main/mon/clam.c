
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a clam");
    set("prevent_summon" , 1);
    set ("long", @EndText
A small clam, enclosed in a white
shell. 
EndText
    );
    set("id" , ({"clam"}) );
    set("stat/constitution", 12);
    set_size(1);
    set_name("clam");
    set("gender", "neuter");
    set("race" , "shellfish");
    set("damage" , ({1, 2}) );
    set("weapon_name" , "shell") ;
    set_verbs( ({"snap at" , "close on" , "bite"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(9);
}
void die() {
    object pearl;
    pearl = clone_object("/d/Ocean/Main/obj/pearl.c");
    if (pearl)
	pearl->move( this_object() );
    say(wrap(
	"The clam releases a pearl from its guts as it dies."
      ));
    ::die() ;
    return ;
}
/* EOF */
