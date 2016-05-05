#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Gnome Supervisor");
    set ("long", @EndText
A gnome who supervises the construction and maintenance of their home.
EndText
);  
    set("id", ({ "gnome", "gnome supervisor" }) );
    set_size(6);
    set_name("gnome") ;
    set("gender", "male");
    set("race", "gnome");
    set("undead", 0);
    set("damage", ({ 5,10 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 1);
    set_level(20);
    set("prevent_summon", 1);
    arm("/d/Prime/Magehouse/weapons/gaxe.c");
    wear("/d/Prime/Magehouse/armor/bplate.c");
    set("chat_chance",4);
    set ("chat_output", ({
"The supervisor checks to make sure all is in order.\n",
"The supervisor inspects the days work.\n",
    }) );

}
