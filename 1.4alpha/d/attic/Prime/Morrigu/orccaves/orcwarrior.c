/*File: orcwarrior.c
Date: 10/97
Purpose: orc warrior for orc caves
Author: Morrigu
Other stuff: Carrys dwarven shortsword for possible quest to come
*/

#include <mudlib.h>

inherit MONSTER;

object sword;

void create ()
{
::create();
seteuid(getuid());
set("short", "an orc warrior");
set("long", @Zugzug
This orc looks like he's been in a few fights and may even be able
to hold his own against a single opponenet.  He's even got a sword!
Zugzug
);
set("id", ({"orc", "orc warrior", "warrior"}));
set("moving", 1);
set("speed", 8);
set_level(2);
set_size(5);
set_name("an orc warrior");
set_living_name("orc warrior");
set("gender", "male");
set("race", "orc");
sword = clone_object("/d/Prime/Morrigu/orccaves/orcsword.c");
sword->move(this_object());
set("damage", ({1,3}));
set("waepon_name", "big hands");
set_verbs(({"backhand", "smack"}));
set_verbs2(({"backhands", "smacks"}));
enable_commands();
set("natt", 1);
}

void init()
{
::init();
command("wield sword");
}
