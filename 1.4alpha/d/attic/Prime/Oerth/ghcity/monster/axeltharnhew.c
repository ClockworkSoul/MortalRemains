#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
set("short", "Axel Tharnhew");
set("long",@Endtext
The proprietor of the Gold Digger Tavern. A long sinced
retired adventurer. He is still renowned as one of the
first great dwarven explorers of the early Flanaess.
Endtext
);
set("id", ({ "axel" }));
set_level(17);
set_size(5);
set_skill("Clubbing Weapons", 5, "strength");
set_name("axel");
set_living_name("axel");
set("gender", "male");
set("race", "dwarf");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/boots.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Oerth/ghcity/weap/hammer.c");
ob2->move(this_object());
ob3=clone_object("/d/Prime/Oerth/ghcity/items/ogregauntlets.c");
ob3->move(this_object());
set("damage", ({10,15}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Axel says: Ahh, welcome to the Gold Digger Tavern.\n",
"Axel asks: Are you adventurers?\n",
"Axel says: I used to adventure, got quite good wit me hammer",
}));
set("chat_att_output", ({
"Axel sneers with rage, 'Starting shit in my bar huh?",
"Axel howls with delight, 'About time for some action.\n",
"Axel says: I going to beat the shit out of you till ya piss in ya pants.\n",
}));
}
void init(){
command("equip boots");
command("equip gauntlets");
command("wield hammer");
command("protect glenda");
}
