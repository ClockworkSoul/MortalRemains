/*File: Orcchief.c
Date: 10/97
Purpose: Orc chieftain for orc level of the caves
More info: later on.*/

#include <mudlib.h>
inherit MONSTER;
object armor, club;

void create()
{
::create();
seteuid(getuid());
set("short", "an orc chieftain");
set("long", @Bing
This orc has somehow become the leader of all the orcs.  He carrys an
enormous club and wears the tribal armor of leadership.  He still looks
like he'd be a pretty easy fight.  Mabey not.
Bing
);
set("id",({"orc", "chieftain", "chief", "orc chieftain"}));
set_level(3);
set_size(6);
set_name("orc chieftain");
set_living_name("orc chieftain");
set("gender", "male");
set("race", "orc");
armor = clone_object("/d/Prime/Morrigu/orccaves/orcleather.c");
armor->move(this_object());
club = clone_object("d/Prime/Morrigu/orccaves/lorcclub.c");
club->move(this_object());
set("damage", ({1,4}));
set_verbs(({"punch", "slap"}));
set_verbs2(({"punches", "slaps"}));
enable_commands();
set("natt", 1);
}

void init()
{
::init();
command("wield club");
command("equip armor");
}
