/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;

void create(){
    ::create();
    seteuid(getuid());
    set("author", "grull");
    set("short", "an oafish looking orc");
    set("long", wrap("This orc has a large, hairy, muscular body. It breathes heavily, grunting often, and smells foul. He doesn't look to be very happy being stuck here."));
    set("id", ({"orc", "Orc"}) );
    set_name("Orc");
    enable_commands();
    set("gender", "male");
    set("race", "orc");
    set("damage", ({ 3,5 }) );
    set("weapon_name", "fists");
    set("stat/strength", 16);
    set("stat/dexterity", 12);
    set_verbs( ({ "punch at", "shove at", "push at" }) );
    set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
    set("chat_chance", 5);
    set("chat_output",
      ({
      "The orc starts pounding its fists on the wall, yelling angrily.\n",
      "A flea jumps out of the orc's hide.\n",
    }));

    set("prevent_summon", 1);
    set_size(8);
    set_level(random(4)+4);
}
