// 22 May 98   Cyanide created the file.

#include "central.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a really rude clerk");
    set("long", wrap(
	"A middle aged, and apparently miserable woman. Her divine "+
	"duty, it would seem, is to spread as much of her displeasure "+
	"and cynicism as possible."
      ) );
    set("id", ({ "clerk", "rude clerk", "woman" }) );
    set("name", query("short") );
    set("cap_name", query("short") );
    set("race", "half-elf");
    set("prevent_summon", 1);
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(40) + 10);
    set("gender", "female");
    set_level(5);

    set("chat_chance", 15);
    set("chat_output", ({
      "The clerk ignores you.\n",
      "The clerk hands you some more papers to fill out.\n",
      "The clerk actively ignores you.\n",
      "The clerk makes a personal phone call.\n",
      "The clerk goes on break for a while, and eventually returns.\n",
    }) );
    set("att_chat_output", ({
      "The clerk screeches for help!\n",
    }) );
    set("attrib1", "rude");
    set("attrib2", "ignorant");
}

void die() {
    object ob, attr;

    attr = TO->query_current_attacker();

    for (int i=2; i>0; i--) {
	ob = clone_object(M_MON+"copbot.c");
	ob->move(environment(TO));
	if (attr) ob->kill_ob(attr);
    }

    message("say", "Two CopBots come crashing into the room!\n",
      all_inventory(environment(TO)) );
    ::die();

}

int kill_ob(object ob) {
    "/adm/daemons/lawd"->add_suspect(ob);
    return ::kill_ob(ob);
}

// EOF
