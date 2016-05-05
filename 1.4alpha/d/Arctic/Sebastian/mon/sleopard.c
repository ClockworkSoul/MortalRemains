/*
	File: sleopard.c
	Date: July 31, 2 triple 0
	Desc: A snow leopard
*/
#include <mudlib.h>
object pelt;
inherit MONSTER;
void create (){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("id", ({"cat", "leopard", "snow leopard"}));
	set("short", "a snow leopard");
	set("long", @Leopard
	A large, majestic arctic feline.  It digs
	at the snow with strong black claws.  It's
	beautiful white coat is speckled with
	black spots.
Leopard
);
	set_size(3);
	set("lore_type", "Animal");
	set_name("snow leopard");
	set_living_name("snow leopard");
	set("gender", "neuter");
	set("race", "leopard");
	set("damage", ({1,8}));
	set("weapon_name", "claws");
	set_verbs(({"swing at", "stab", "swipe at"}));
	set_verbs2(({"swings at", "stabs", "swipes at"}));
	set("stat/dexterity", 18);
	enable_commands();
	set("chat_chance", 5);
set("chat_output", ({"the snow leopard yawns, baring it's fangs.\n"}));
	set("att_chat_output",({"the snow leopard growl angrily.\n"}));
	pelt = clone_object("/u/s/sebastian/items/lpelt.c");
	pelt->move(this_object());
	set_level(9);
}
