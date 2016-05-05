#include <mudlib.h>
#include <def.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "a garden snake");
    set("long", wrap(
	"A small garden snake slithers before you. He is bright green in color with "+
	"tiny yellow spots lining his back."
      ) );
    set("id", ({"snake"}));
    set_level(4);
    set_size(1);
    set_name("snake");
    set("gender", "male");
    set("race", "reptile");
    set("damage", ({3,5}));
    set("weapon_class", "fangs");
    set_verbs(({"bite", "pierce"}));
    set("natt", 1);
    set("chat_chance", 5);
    set("chat_output", ({
      "The green snake slithers about on the ground.\n",
      "The green snake slides silently before you.\n",
    }) );
    set("att_chat_output", ({
      "The green snake bares his fangs.\n",
      "The garden snake looks up menacingly.\n",
    }) );
    credit(8);
}
