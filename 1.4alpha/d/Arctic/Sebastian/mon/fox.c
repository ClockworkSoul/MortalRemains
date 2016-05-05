/*
	File: Fox.c
	Desc: An Arctic fox, not as big as a wolf, but kinda wily
	Date: July 1,1 triple 9.  Woo Hoo!
	Other Comments: It's sportin a pretty keen pelt too!
*/
#include <mudlib.h>
object pelt;
inherit MONSTER;
void create()
{
    ::create();
    seteuid(getuid());
    set("author", "sebastian");
    set("short","arctic fox");
    set("long",@Fox
Standing slightly over a foot tall, it darts around aimlessly.
It's fur shines dimly.  It looks like it would be worth a few
credits at the general store.  It's deep blue eyes are calm and
pure.  There isn't an evil thought in it's head.
Fox
    );
    set("id",({"fox","arctic fox","arcticfox","animal","dog"}));
    set_name("arctic fox");
    set_size(1);
    set("gender","neuter");
    set("race","fox");
	set("lore_type", "Animal");
    set("weapon_name","claws");
    set("damage",({1,3}));
    set("damage_type","slashing");
    set_verbs(({"swing at","paw at","bat at","claw at","slice"}));
    set_verbs2(({"swings at","paws at","bats at","claws at","slices"}));
    set("chat_chance",3);
    set("chat_output",({"The fox looks around aimlessly.\n",
      "The fox sniffs the ground.\n",
      "The fox licks it's nose and lips hungrily.\n",
      "The fox barks and howls playfully.\n"}));
    set("att_chat_output","The fox howls in pain, whimpering.\n");
    set("stat/dexterity",16);
	set_level(5);
    enable_commands();
    pelt = clone_object("/u/s/sebastian/items/fpelt.c");
    pelt->move(this_object());
}
