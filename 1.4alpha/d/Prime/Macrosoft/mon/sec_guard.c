// A cheapo security guard. Good for little more
// than eating donuts.

#include "macrosoft.h"

inherit MONSTER;

void create() {
    object badge;

    ::create();
    set("short", "a drowsy security guard");
    set("long", wrap("This security guard seems to be "+
	"more interested in his box of donuts than in his "+
	"surroundings."
      ) );
    set("id", ({ "guard", "security guard", "oscar" }) );
    set_name("Oscar");
    set("attrib1", "out of shape");
    set("attrib2", "balding");
    set("author", "cyanide");
    set("damage", ({ 1, 4 }) );
    set("race", "human");
    set("weapon_name", "fists");
    set("gender", "male") ;
    set_verbs( ({ "swing at" }) );
    arm("/d/Prime/Central/weap/stungun.c");
    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(2);
    wear(badge);
    set_level(4);
}

/* EOF */
