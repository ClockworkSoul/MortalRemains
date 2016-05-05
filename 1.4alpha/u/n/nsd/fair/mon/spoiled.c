/*
** File: spoiled.c
** Author: Lady Nsd
*/

#include <mudlib.h>
#include "fair.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "a spoiled teen");
    set("long", @EndText
This fastidious teen belongs to a gang of trouble makers.
He will bug just for the fun of it. He's wearing worned
jeans, a black t-shirt of Degeneration X, and a black
leather jacket. Seems like he's hiding something inside
his pockets.
EndText);
    set("id", ({"teen", "spoiled", "spoiled teen"}) );
    set_size(6);
    set_name("spoiled teen");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "spoiled teen starts to jump on the moonwalk.\n",
      "spoiled teen says [to you] : Get outta my way, fuckin puss!!\n",
      "spoiled teen pushes you out of the way!!\n",
      "spoiled teen says [to you] : c'mon, c'mon, hit me if you have\n"+
      "the guts, puss!!\n",
      "spoiled teen gets a grip inside of his pocket...\n",
      "spoiled teen fists you in the face just for the fun of it!\n",
      "spoiled teen says [to you] : what a FAGGOT!!! ... and mocks you.\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
    arm(FAIR_OBJ+"knife.c");
}
/* EOF */
