#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Ice Thing");
    set ("long", @EndText
Its a thing, made of ice.
What else do you wanna see?
EndText
);  
    set("id", ({ "monster", "thing", "ice thing" }) );
    set_size(3);
    set_name("thing") ;
    set("gender", "female");
    set("race", "thing");
    set("undead", 0);
    set("damage", ({ 2,8 }) );
    set("weapon_name", "things") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(3);
    credit(200);
    arm("/d/Prime/Magehouse/weapons/iwhip.c");
}
