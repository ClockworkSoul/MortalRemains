/*File: orccook.c
Date: 1/11/98
Purpose: He makes food for orcs.
Other Purpose: He makes lunch out of characters.
Neat stuff: He has a cleaver and he knows how to use it.
*/

#include <mudlib.h>
inherit MONSTER;

object cleaver;

void create()
{
::create();
seteuid(getuid());
set("short", "an orc cook");
set("long", @Bingo
This large, fat orc is cooking stuff that looks vaguely like the remains
of your friends.  He looks mad.
Bingo
);
set("id", ({"orc", "orc cook", "cook", "orccook"}));
set("speed", 5);
set("patrol", ({"west", "east", "east", "west", "north", "south"}));
set_level(2);
set_size(6);
set_name("orc cook");
set_living_name("orc cook");
set("gender", "male");
set("race", "orc");
set_skill ("Short Blades", 2, "Strength");
cleaver = clone_object("d/Prime/Morrigu/orccaves/cleaver.c");
cleaver->move(this_object());
set("damage", ({1,6}));
set("weapon_name", "ham sized fists");
set_verbs(({"smack", "punch", "slam"}));
set_verbs2(({"smacks", "punches", "slams"}));
enable_commands();
set("natt", 1);

}

void init(){
::init();
command("wield cleaver");
}
