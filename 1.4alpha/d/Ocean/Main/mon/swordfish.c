
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a swordfish");
    set("prevent_summon" , 1);
    set ("long", @EndText
It has an incredibly sharp looking pointed nose. 
EndText
    );
    set("id" , ({"swordfish" , "fish"}) );
    set_size(3);
    set_name("swordfish");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage_type" , "slashing");
    set("weapon_name" , "nose");
    set_verbs( ({"slash at" , "swipe at" , "stab at"}) );
    set_verbs2( ({"slashes at" , "swipes at" , "stabs at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(15);
}
void die() {
    object sword;
    sword = clone_object("/d/Ocean/Main/weap/sword.c");
    if (sword)
	sword->move( this_object() );
    say(wrap(
	"The nose of the swordfish breaks off. "
      ));
    ::die() ;
    return ;
}
/*EOF*/
