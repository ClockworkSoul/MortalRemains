#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
 set("short", "Nightwatchman");
set("long",@Endtext
Standing before you is one of Greyhawk's elite
Nightwatchman. He has a very serious look on
his face. He also looks like he can utterly
fuck up your world.
Endtext
);
set("id", ({ "guard", "nightwatchman" }));
set_level(12);
set_size(6);
set_skill("Axes", 5, "strength");
set("stat/strength", 18);
set("stat/dexterity", 18);
set("stat/constitution", 19);
set_name("nightwatchman");
set_living_name("nightwatchman");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/boots.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Oerth/ghcity/armour/platemail2.c");
ob2->move(this_object());
ob3=clone_object("/d/Prime/Oerth/ghcity/weap/battleaxe.c");
ob3->move(this_object());
set("damage", ({10,15}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Guard says: Greetings noble sir, welcome to Greyhawk City.\n",
"Guard says: Keep to yourself and you won't get in trouble.\n",
"Guard says: What are you looking at, you want to try a piece of this?\n",
}));
set("chat_att_output", ({
"Guard grins excitedly and says: No cell for you, only death.\n",
"Guard says: Oh great, another dork trying to make a name.\n",
"Guard says: Oh please noble sir, please stop while you have a chance.\n",
}));
}
void init(){
command("equip");
command("wield battleaxe");
command("protect nightwatchman");
}
