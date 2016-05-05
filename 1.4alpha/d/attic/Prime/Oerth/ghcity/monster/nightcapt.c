#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
set("short", "Captain");
set("long",@Endtext
Standing before you is one of Greyhawk's elite
Nightwatchman. He has a very serious look on
his face. He also looks like he can utterly
fuck up your world.
Endtext
);
set("id", ({ "guard", "captain" }));
set_level(18);
set_size(6);
set_skill("Whips", 5, "strength");
set_skill("One Weapon Style", 1, "strength");
set("stat/strength", 18);
set("stat/dexterity", 18);
set("stat/constitution", 19);
set_name("Captain");
set_living_name("Captain");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/boots.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Oerth/ghcity/armour/platemail2.c");
ob2->move(this_object());
ob3=clone_object("/d/Prime/Oerth/ghcity/weap/whip.c");
ob3->move(this_object());
set("damage", ({10,15}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Captain asks you: Anything I can help you with?",
"Captain says: Please leave, I have alot of work to do.",
"Captain says: GUARDS! Get this peasant out of my office.",
}));
set("chat_att_output", ({
"Captain grins and says: Now that was fucking dumb.",
"Captain cackles gleefully and circles around you.",
"Captain whispers to you: Say hello to death for me.",
}));
}
void init(){
command("equip");
command("wield whip");
}
