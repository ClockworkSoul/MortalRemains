// 22 May 98   Cyanide created the file.

#include "central.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "Jeff, the friendly salesperson");
    set("long", wrap(
	"Jeff is a young and overly enthusiastic salesperson. "+
	"There is a name tag fastened to his perfectly ironed "+
	"white shirt."
      ) );
    set("prevent_summon", 1);
    set("id", ({ "salesman", "salesperson", "jeff" }) );
    set_name("Jeff");
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(40) + 10);
    set("gender", "male");
    set_level(5);

    set("chat_chance", 15);
    set("chat_output", ({
      "Jeff says, 'Can I help you with something?'\n",
      "Jeff says, 'That item comes with a free cellular phone!'\n",
      "Jeff follows you around the store.\n",
      "Jeff smile widely.\n",
      "Jeff adjusts his tie.\n",
      "Jeff says, 'Hi! I'm Jeff!'\n",
    }) );
    set("att_chat_output", ({
      "The clerk screeches for help!\n",
    }) );
    set("attrib1", "youthful");
    wear(M_OBJ+"nametag.c", "tag");
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

    ::die();

}
