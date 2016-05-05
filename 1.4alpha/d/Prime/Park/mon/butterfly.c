#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "a colorful butterfly");
    set("author", "ellie");
    set("long", wrap(
	"A brightly colored butterfly flits about happily. Her wings are mostly "+
	"blue, with pink accents throughout. She is quite lovely."
      ) );
    set("id", ({"butterfly"}));
    set_size(1);
    set_name("butterfly");
    set("gender", "female");
    set("race", "insect");
    set("damage", ({1,2}));
    set("weapon_name", "tiny teeth");
    set_verbs(({"bite", "gnaw"}));
    set("chat_chance", 5);
    set("chat_output", ({
      "The butterfly glides gracefully on the breeze.\n",
      "The butterfly flaps her gossamer wings.\n",
    }) );
    set("att_chat_output", ({
      "The butterfly flaps her wings furiously.\n",
      "The butterfly looks for a place to hide.\n",
    }) );
    set_level(1);
    credit(5);
}
