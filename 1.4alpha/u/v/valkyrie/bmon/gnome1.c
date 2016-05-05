#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Gnome Worker");
    set ("long", @EndText
This breed of gnome rests below the house of a great and powerful mage
because they have the unique ability to harness the powers of the
universe, more so than other beings who wield such power.
EndText
);  
    set("id", ({ "gnome", "gnome worker" }) );
    set_size(6);
    set_name("gnome") ;
    set("gender", "male");
    set("race", "gnome");
    set("undead", 0);
    set("damage", ({ 10,15 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 1);
    set_level(6);
    set("prevent_summon", 1);
    arm("/d/Prime/Magehouse/weapons/pick.c");
    wear("/d/Prime/Magehouse/armor/mhelmet.c");
    wear("/d/Prime/Magehouse/armor/mgloves.c");
}
