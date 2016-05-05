
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "valkyrie");
    set("short", "A Huge Bear");
    set ("long", @EndText
This huge black bear resides in this cave. It looks you over slowly,
licking his chops, his fang glow in the low lighting of the cave. His gaze
makes you very uncomfortable as do his large, sharp-looking cybernetic
claws.
EndText
);  
    set("id", ({ "monster", "bear" }) );
    set_size(8);
    set_name("bear") ;
    set("gender", "male");
    set("race", "bear");
    set("undead", 0);
    set("damage", ({ 1,5 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 2);
    set ("chat_chance", 3);
    set ("chat_output", ({
     "The bear licks his chops and drools at the sight of you.\n",
      "The bear growls menacingly at you.\n",
    }) );
    set ("att_chat_output", ({
     "The bear growls menacingly at you.\n",
    }) );
        
    set_level(10);
 set ("base_stat",([
        "strength" : 18,
        "constitution" : 20,
        "dexterity" : 12 ]) );

    
    arm("/d/Prime/Kyrie/weapons/laser_claw.c") ;
}
