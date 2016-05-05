#include <mudlib.h>

inherit MONSTER ;

#include "../food.h"

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
   set("prevent_summon", 1);
   set("short", "the Baker");
    set ("long", @EndText
This is the baker, the good people of Foodsburg have captured him
and locked him up here by burying his pants in the front yard so
he can never leave this room, damn that VooDoo.
EndText
   );
   set("id", ({ "baker", "human" }) );
   set_size(4);
   set_name("baker");
   set("wealth", random(25));
    set("gender", "neuter");
   set("race", "human");
    set("damage", ({ 1,4 }) );
   set("weapon_name", "fists");
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
   set_level(5);
   arm(WEAP+"fork.c");
   wear(ARM+"apron.c");
}
