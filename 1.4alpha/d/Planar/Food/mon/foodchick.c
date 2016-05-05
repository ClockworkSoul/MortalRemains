#include <mudlib.h>

inherit MONSTER ;

#include "../food.h"

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
   set("prevent_summon", 1);
   set("short", "cheesecake villager");
    set ("long", @EndText
This is a cheesecake villager. They look yummy to eat, but you might
have to kill them first.
EndText
   );
   set("id", ({ "cheesecake", "villager" }) );
   set_size(4);
   set_name("cheesecake");
   set("wealth", random(25));
    set("gender", "neuter");
   set("race", "dessert");
    set("damage", ({ 1,4 }) );
   set("weapon_name", "creamy fists");
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
   set_level(random(3));
   arm(WEAP+"licorice.c");
   wear(ARM+"candy.c");
   wear(ARM+"candyboots.c");
}
