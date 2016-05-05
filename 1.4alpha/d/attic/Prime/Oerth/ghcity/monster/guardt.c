#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
set("short" , "Greyhawk City Guard");
set("long",@Endtext
Standing proudly before you is one of Greyhawk Cities
many guard. He is tall, strong and very well equipped.
He looks like a seasoned warrior and likely to kick
your ass.
Endtext
);
set("id", ({ "guard" }));
set_level(30);
set_size(6);
set_skill("Long Blades", 5, "strength");
set("stat/strength", 18);
set("stat/dexterity", 18);
set("stat/constitution", 19);
set("stat/charisma", 13);
set("stat/wisdom", 12);
set("stat/intelligence", 12);
set_name("guard");
set_living_name("guard");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/boots.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Oerth/ghcity/armour/platemail.c");
ob2->move(this_object());
ob3=clone_object("/d/Prime/Oerth/ghcity/weap/longsword.c");
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
command("wield sword");
command("protect guard");
}
