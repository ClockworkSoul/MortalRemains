#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
set("short", "A Patron");
set("long",@Endtext
This is a guy drinking some shit and running his mouth.
Endtext
);
set("id", ({ "patron" }));
set_level(4);
set_size(5);
set_name("patron");
set_living_name("patron");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Oerth/ghcity/armour/boots.c");
ob1->move(this_object());
set("damage", ({3,8}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
}
void init(){
command("equip boots");
}
