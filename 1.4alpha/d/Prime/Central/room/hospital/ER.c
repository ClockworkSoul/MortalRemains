// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 27 June 1999

inherit ROOM;

#define OKAY            0
#define FEEBLEMINDED    1
#define WOUNDED         2
#define BLIND           4

#include "central.h"

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("safe", 1);
    set("light", 1);
    set("short", "Emergency Room");
    set("long", wrap(
	"This is the emergency room, where the most immediate ailments "+
	"can be dealt with. There is a nurse behind the counter."
      ) );
    set("exits", ([
      "east" : M_ROOM+"hospital/lobby.c",
    ]) );
    set("item_desc", ([
      "nurse" : "@@query_nurse_exa"
    ]) );
}


int receive_object (object ob) {
    call_out("nurse_look", 1, ob);
    return 1;
}

int is_he_okay(object ob) {
    if (!ob || !living(ob)) return OKAY;

    if (present("#FEEBLEMIND#", ob)) return FEEBLEMINDED;

    if (present("#WOUND_OB#", ob)) return WOUNDED;

    if (ob->query("blind")) return BLIND;

    return OKAY;
}

void nurse_look(object ob) {
    string str = "The nurse says {to $N]: ";

    if (!userp(ob)) return;

    switch(is_he_okay(ob)) {
    case OKAY : str = "The nurse looks at you for a moment, and "+
	"goes back to doing paperwork."; break;
    case FEEBLEMINDED : str += "You've been feebleminded!\n"; break;
    case WOUNDED : str += "You've been terribly wounded!\n"; break;
    case BLIND : str += "You're blind!\n"; break;
    default : str += "I've never seen that before!\n"; break;
    }

    tell_object(ob, iwrap(replace_string(str, "$N", "you")));
    say(iwrap(replace_string(str, "$N", ob->query("cap_name"))),
      ({ ob }) );

    return;
}

/* EOF */
