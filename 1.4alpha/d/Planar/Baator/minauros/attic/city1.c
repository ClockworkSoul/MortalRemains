#include <mudlib.h>
#include "baator.h"

#define OKAY            0
#define FEEBLEMINDED    1
#define WOUNDED         2
#define BLIND           4

//inherit "/d/Outer/Sigil/healers.c";
inherit "/d/Prime/Central/room/hospital/ER.c";

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", wrap("You are in the sinking city of Minauros "+
	"itself. A small hovel with some healers have set up shop "+
	"to aid those in need.") );
    set ("short","Sinking city of Minauros");
    set ("exits", ([   
      "south" : BAATOR+"minauros/city3.c"
    ]));
}


void nurse_look(object ob) {
    string str = "The healer says [to $N]: ";

    if (!userp(ob)) return;

    switch(is_he_okay(ob)) {
    case OKAY : str += "Oh, you're fine. Get back out there."; break;
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
