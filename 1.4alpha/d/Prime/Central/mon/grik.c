// 22 May 98   Cyanide created the file.

#include "central.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());

    set("prevent_summon", 1);
    set("author", "cyanide");
    set("short", "Grik, the Arms Dealer");
    set("long", wrap(
	"Grik is a hardened veteran of what appears to be many, many "+
	"battles. His face is a web of old scars, and his left eye is "+
	"covered by a patch. In addition, his right arm has been "+
	"replaced with an old military surplus cybernetic claw."
      ) );
    set("id", ({ "salesman", "salesperson", "grik" }) );
    set_name("Grik");
    set("lore", wrap("Local legend holds that Grik is a veteran of the "+
	"Unhuman Wars of the last century, having been highly decorated. "+
	"When the war ended, his lust for carnage was unfulfilled, and he "+
	"continued to fight for profit and personal entertainment. Now, "+
	"his bloodlust partially sated, he lives vicariously through the "+
	"patrons of his humble shop.") );
    set("race", "half-orc");
    set("weapon_name", "claw");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 2, 8 }) );
    credit(random(140) + 10);
    set("gender", "male");
    set("ammo", ([ ".44" : 10000 ]) );
    set("attrib1", "grisly");
    set("attrib2", "battle-scarred");
    set_level(25);
    set_skill("Small Arms", 4, "strength");
    set_skill("Unarmed", 2, "strength");
    arm(M_WEAP+"magnumrev.c", "magnum");

    set("chat_chance", 7);
    set("chat_output", ({
      "Grik eyes you warily.\n",
      "Grik watches you with his one good eye.\n",
      "Grik cleans the counter.\n",
      "Grik spits.\n",
      "Grik slowly cleans his gun.\n",
    }) );
    set("att_chat_output", ({
      "Grik attacks you with immense pleasure.\n",
    }) );
}

void die() {
    object ob, attr;

    if (!random(3)) {
	attr = TO->query_current_attacker();

	for (int i=2; i>0; i--) {
	    ob = clone_object(M_MON+"copbot.c");
	    ob->move(environment(TO));
	    if (attr) ob->kill_ob(attr);
	}

	message("say", "Two CopBots come crashing into the room!\n",
	  all_inventory(environment(TO)) );
    }

    set("ammo", ([ ".44" : 2 ]) );

    ::die();

}

// EOF
