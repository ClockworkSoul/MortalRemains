#include <mudlib.h>

inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;  
    set("author", "blood");
    set("short", "Fire Bug");
    set ("long", @EndText
A slim torso acompanied by huge arms with 8 fingered hands two large
clawed feet, and the ugliest head with a backward nose you've ever seen.
oh, did i mention he is made of fire?
EndText
);       
    set("id", ({ "monster", "bug", "firebug" }) );
    set_size(6);
    set_name("firebug") ;
    set("gender", "male");
    set("race", "firebug");
    set("undead", 0);
set("damage", ({ 9,14}) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 3);
    set_level(14);
    set("prevent_summon", 1);
    credit(200);
    arm("/d/Prime/Magehouse/weapons/fdagger.c");
}
