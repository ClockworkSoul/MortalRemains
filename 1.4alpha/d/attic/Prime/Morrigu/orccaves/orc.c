/*File: corc.c
purpose: orc base for the metamorph to come.
Author: Morrigu
Date: 9/97
Other stuff: Not yet*/
#include <mudlib.h>
inherit MONSTER;
object club;
void create()
{
::create();
seteuid(getuid());
set("short", "an orc");
set("long", @Slime
It's a short, stout, ugly, mean looking humaniod, and it's dummer than
it looks, if that's possible.
Slime);
set("id", ({"orc"}));
set("moving", 1);
set("speed", 10);
set_level(2);
set_size(5);
set_name("an orc");
set_living_name("orc");
set("gender", "male");
set("race", "orc");
club = clone_object("/d/Prime/Morrigu/orccaves/orcclub.c");
club->move(this_object());
enable_commands();
set("damage", ({1,4}));
set("weapon_name", "hairy fists");
set_verbs(({"punch", "smack", "backhand"}));
set_verbs2(({"punches", "smacks", "backhands"}));
set("natt", 1);
}
void init()
{
::init();
command("wield club");
}
