#include <mudlib.h>
inherit MONSTER;

void create(){
object ob1;
::create();
seteuid(getuid());
set("short", "Citizen");
set("long", @Endtext
This is one of the many citizens that inhabit Duegne. He seems
to be oblivious to all the activity that is going on around here.
While they may not cause any trouble, the citizens don't seem
very talkative either.
Endtext
);
set("id", ({"citizen", "man"}));
set_level(3);
set("moving", 1);
set_size(5);
set_name("Jon");
set_living_name("Jon");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Krynn/armor/animalhide.c");
ob1->move(this_object());
set("damage", ({2,8}));
set("weapon_name", "fists");
set_verbs(({"punch", "smack", "hit"}));
set_verbs2(({"punches", "smacks", "hits"}));
enable_commands();
set("wealth", 50 + (random(50)));
}
void init(){
command("equip");
}
