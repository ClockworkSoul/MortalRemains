#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Emph");
    set ("long", @EndText
Emph, is a large scaly monster it has long claws which extend directly
from its body as if they were hands. A large six eyed head sits atop this
ugly bastard.
EndText
);  
    set("id", ({ "monster", "emph" }) );
    set_size(8);
    set_name("emph") ;
    set("gender", "male");
    set("race", "emph");
    set("undead", 0);
    set("damage", ({ 20,40 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(22);
    set("prevent_summon", 1);
    credit(200);
    arm("/d/Prime/Magehouse/weapons/severstaff.c");
}
