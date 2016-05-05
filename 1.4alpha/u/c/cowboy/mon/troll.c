#include <mudlib.h>
#include "/u/c/cowboy/include/defs.h"

inherit MONSTER;

object club;
void create() {
           ::create();
           seteuid(getuid() );
enable_commands();
set("author", "Cowboy");
set("short", "troll");
set("long", @TROLL
A vicious looking creature the size of a medium sized human
but weighs a little less than a 250 pounds. He is well
built. He is wearing battered looking clothing with holes
all through them. His eyes are bloodshot and he has a
hungry look about him.
TROLL
);
set("id", ({ "troll" }) );
set_level(6);
set_name("troll");
set("gender", "male");
set("race", "troll");
set("damage", ({ 1,4 }) );
set("weapon", "fists");
set_verbs(({ "attack", "punches at", "swing at" }));
club = CO("/u/c/cowboy/weapons/club.c");
club->move(this_object());
arm(M_WEAP+"club.c", "club");
set("natt", 1);
command("wield club");
}
