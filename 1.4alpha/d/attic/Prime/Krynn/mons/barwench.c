#include <mudlib.h>
inherit MONSTER;

void create(){
object ob1;
::create();
seteuid(getuid());
set("short", "A barwench");
set("long", @Endtext
She is one of your standard bar wenches. She seems to linger
around any patron that even looks like he has money. Dressed
in a very short dress, she is showing plenty of leg and
cleavage to go around.
Endtext
);
set("id", ({"wench", "barwench", "girl", "slut", "whore"}));
set_level(5);
set_name("Toni");
set_living_name("Toni");
set("gender", "female");
set("race", "elf");
ob1=clone_object("/d/Prime/Krynn/armor/dress.c");
ob1->move(this_object());
set("damage", ({5,10}));
set("weapon_name", "nails");
set_verbs(({"rake", "claw", "scratch"}));
set_verbs2(({"rakes", "claws", "scratches"}));
enable_commands();
set("wealth", 100 + (random(100)));
set("chat_chance", 10);
set("chat_output", ({
"Wench says: Hey there sugar, want me to show you a good time?\n",
"Wench says: Wow, ain't you a sexy little thing?\n",
"Wench says: Why don't we go get a room and have some hot monkey love?\n",
}));
set("att_chat_output", ({
"Wench screams: That's it. No monkey love for you god damnit!\n",
"Wench screams: What the hell?! Guess you don't like me huh?\n",
"Wench screams: Guess this means I am not getting paid then huh?\n",
}));
}
void init(){
command("equip");
}
