
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a shark");
    set("prevent_summon" , 1);
    set ("long", @EndText
This shark is really mean looking. He has huge sharp teeth.
EndText
    );
    set("id" , ({"shark"}) );
    set_size(10);
    set_name("shark");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({3,8}) );
    set("damage_type" , "slashing");
    set("weapon_name" , "teeth");
    set_verbs( ({"gnaw on" , "rip" , "tear into"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
      "The shark circles around you.\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(23);
}
void die() {
    object tooth;
    tooth = clone_object("/d/Ocean/Main/obj/tooth.c");
    if (tooth)
	tooth->move(this_object() );
    say(wrap(
	"One of the shark's teeth is broken off. "
      ));
    ::die();
    return;
}
