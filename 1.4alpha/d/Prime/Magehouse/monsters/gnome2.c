#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Gnome Guard");
    set ("long", @EndText
This tough-looking gnome has been assigned the duty of patrolling the
mines, keeping adventurers like you out.
EndText
);  
    set("id", ({ "gnome", "gnome guard" }) );
    set_size(6);
    set_name("gnome") ;
    set("gender", "male");
    set("race", "gnome");
    set("undead", 0);
    set("damage", ({ 10,15 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 1);
    set_level(30);
    set("prevent_summon", 1);
    arm("/d/Prime/Magehouse/weapons/gaxe.c");
    wear("/d/Prime/Magehouse/armor/bplate.c");
    set("chat_chance",4);
    set ("chat_output", ({
"The guard watches you closely.\n",
"The guard glances around, looking for potential danger.\n",
    }) );
}

