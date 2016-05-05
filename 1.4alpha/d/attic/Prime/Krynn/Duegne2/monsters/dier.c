#include <mudlib.h>
inherit MONSTER;

object ob1, ob2;
void create(){
::create();
set("short", "Dierguard");
set("long", "An evil Dierguard. He is a skeleton clothed in dark armour that seems to be transparent. Bright, fire red orbs sit in what used to be his eye sockets.\n");
set("id", ({"guard", "dierguard", "skeleton"}));
set("race", "skeleton");
set_name("dierguard");
set_level(15);
set("damage", ({ 10, 50 }) );
set("undead", 1);
set_verbs(({"lunge", "stab"}));
set_verbs2(({"lunges", "swipes"}));
ob1=clone_object("/d/Prime/Krynn/Duegne2/weapons/direswrd.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Krynn/Duegne2/armour/blck_chainmail.c");
ob2->move(this_object());
enable_commands();
}
void init(){
command("equip");
command("wield sword");
}
