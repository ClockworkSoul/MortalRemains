
#include <mudlib.h>
#include "ocean.h";

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a scuba diver");
    set("prevent_summon" , 1);
    set ("long", @EndText
This is a man who spends all his free time swimming,
and diving in the ocean. He loves looking at all the
sea life around here.
EndText
    );
    set("id" , ({"diver" , "man" , "scuba" , "scuba diver"}) );
    set("stat/constitution", 12);
    set_size(6);
    set("wealth" , 110);
    set_name("diver");
    set("gender" , "male");
    set("race" , "human");
    set("damage" , ({1, 2}) );
    set("weapon_name" , "fists");
    set_verbs( ({"hit" , "attack" , "lunge at" , "pummel"}) );
    set("chat_chance" , 6);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    wear(O_OBJ+"wetsuit.c");
    wear(O_OBJ+"flipper.c");
    arm(O_OBJ+"tank.c");
    set_level(11);
}
