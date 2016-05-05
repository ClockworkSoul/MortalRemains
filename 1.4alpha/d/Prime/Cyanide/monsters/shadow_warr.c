#include "monsters.h"
#include <mudlib.h>

inherit MONSTER;

void create () {
    ::create();
    seteuid(geteuid()) ;
    enable_commands();

    set("author", "cyanide");

    //Happy Happy ID Stuff
    set("short", "a heavily armed shadow warrior");
    set("long", "Though you can barely make out his form in \n"+
      "the gloom, you can see a vaguely humanoid shape composed\n"+
      "of the very essence of shadow, heavily armed and armored.\n");
    set ("id", ({ "shadow", "warrior", "shadow warrior" }) );
    set("race", "shadow warrior");
    set ("gender", "male");
    set_name("shadow warrior");
    set_living_name("warrshad");
    set("lore_type", "demon");
    set("lore", wrap(
	"Little is known of this reclusive and xenophobic race, except "+
	"that they live in vast numbers on the Plane of Shadow, occasionally "+
	"coming to this plane to steal supplies, magic, and living mortals."
      ) );

    //Mass and other related physical stats:
    set_size(6);

    //Stats + Skills:
    set("stat/strength", 22);
    set("stat/dexterity", 24);
    set_skill("Long Blades",3,"dexterity");

    //What he has...
    wear(OBJ+"/sh_cloak.c", "cloak");
    arm(OBJ+"/sh_sword.c", "sword");
    credit(800+random(250));

    //Just about everything related to combat:
    set ("aggressive", 1);
    set ("armor_class", 1);
    set ("damage", ({ 3,10 }) );
    set ("natt", 2);
    set ("weapon_name", "shadowy existance" );
    set ("damage_type", "cold");
    set ("pursuing", 1);
    set("weap_resist", 2);
    set("resist_type", ([
      "cold" : -100,
      "dehydration" : 50,
      "poison" : 0,
      "suffocation" : 0,
    ]) );
    set_level(20);

    //Chats and stuff
    set_verbs( ({ "swing at", "attack" }) );
    set("chat_chance", 10);
    set("att_chat_output", ({
      wrap("The dark warrior plunges his shadowstuff into you, "+
	"absorbing some of your life essence!"),
    }));
}
