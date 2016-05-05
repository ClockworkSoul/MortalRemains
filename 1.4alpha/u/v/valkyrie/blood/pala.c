#include <mudlib.h>

inherit MONSTER ;
    
void create () {
    ::create();
    seteuid(getuid());   
    enable_commands() ;  
    set("author", "blood");
    set("short", "Pala");
    set ("long", @EndText  
Pala, a warrior from the second age carries herself with an honorable
bearing, waisting no time with social chatter, she looks you up and down,
waiting for your challenge.
EndText
);       
    set("id", ({ "pala", "warrior" }) );
    set_size(7);
    set_name("pala") ;
    set("gender", "female");
    set("race", "warrior");
    set("undead", 1);
    set("damage", ({ 5,15 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 2);
    set_level(16);
    set("prevent_summon", 1);
    credit(400);
    arm("/d/Prime/Magehouse/weapons/deadsword.c");
}
