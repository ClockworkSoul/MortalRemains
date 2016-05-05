#include <mudlib.h>
inherit MONSTER;

void create()
{
object ob1, ob2, ob3;
::create();
seteuid(getuid());
set("short", "Duegne Gate Guard");
set("long",@Endtext
This is one of the famed gate guards of Duegne. Sworn to protect
these gates from invaders, they shall do whatever it takes to
keep this oath. He is tall and muscular, his arms bulging under
the crimson cloak he wears. His face is like solid stone, his 
gaze one that would pierce the hide of a dragon. He looks you up
and down as you stand here and you hope he can forget you rather
quickly.
IF YOU ATTACK HIM, YOU WILL DIE!!!!
Endtext
);
set("id", ({ "guard" }));
set_level(1);
set_size(7);
set("stat/strength", 25);
set_name("guard");
set_living_name("guard");
set("gender", "male");
set("race", "human");
ob1=clone_object("/d/Prime/Krynn/armor/cloak1.c");
ob1->move(this_object());
ob2=clone_object("/d/Prime/Krynn/armor/boots1.c");
ob2->move(this_object());
ob3=clone_object("/d/Prime/Krynn/armor/plate1.c");
ob3->move(this_object());
set("damage", ({5000000,10000000}));
set("weapon_name", "hands");
set_verbs(({"punch", "smack", "slap", "hit"}));
set_verbs2(({"punches", "smacks", "slaps", "hits"}));
enable_commands();
set("class", "WARRIOR");
set_skill("Long Blades", 6, "Strength");
set("wealth", 500+(random(600)));
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Guard says: Welcome to Duegne. May you always find water and shade.\n",
"Guard says: Do not cause trouble here. We look forward to dancing the swords.\n",
}));
set("chat_att_output", ({
"Guard says: You shall no see what it is like to dance the swords.\n",
"Guard says: I will show you no quarter. Your blood shall stain the cobblestones before I am through.\n",
"Guard says: You should have left when you had the chace. Now you shall die.\n",
}));
}
void init(){
command("equip");
command("wield sword");
}
