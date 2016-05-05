#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2;
::create();
seteuid(getuid());
set("short", "Glenda Silvertoe");
set("long",@Endtext
This cute little halfling is the chief barmaid.
She presides over the bar when Axel isn't around.
For a short little woman, she seems quite nimble.
Endtext
);
set("id", ({ "glenda" }));
set_level(13);
set("size", 5);
set_skill("Short Blades", 4, "strength");
set_name("glenda");
set_living_name("glenda");
set("gender", "female");
set("race", "halfling");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/cloak1.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Oerth/ghcity/weap/shortsword.c");
ob2->move(this_object());
set("damage", ({10,15}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Glenda says: Greetings, and welcome to the Gold Digger.\n",
"Glenda eyes your dreamily.\n",
"Glenda makes a quick glance towards your purse.",
}));
set("chat_att_output", ({
"Glenda says: Why you little fuck!\n",
"Glenda's eyes gleam as she circles you.\n",
"Glenda says: No one starts trouble in here.\n",
}));
}
void init(){
command ("equip");
command("wield sword");
command("protect axel");
}
