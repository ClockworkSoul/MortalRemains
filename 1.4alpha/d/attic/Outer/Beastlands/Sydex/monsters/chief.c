#include <mudlib.h>
inherit MONSTER ;
 
void create () {
object spear;
::create();
seteuid(getuid());
set("short", "The chief of the village");
set ("long", @Foo
This is the chief of the village. He has a trobled brow.
He is dressed only in a loin cloth.
Foo
);
set("id", ({ "chief" }) );
set_level(15);
set_size(6);
set_name("chief");
set("gender", "male");
set("race", "Human");
spear = clone_object("/d/Outer/Beastlands/Sydex/weap/spear.c");
spear->move(this_object());
set("aggressive", 1);
set("damage", ({ 2,8 }) );
set("weapon_name", "fists");
set_verbs( ({ "swipes at", "punches at", "smashes at" }) ) ;
enable_commands() ;
set("natt", 2);
set ("chat_chance", 6);
set ("chat_output", ({
"The chief mumbles something about the shaman in the temple.\n",
}) );
set ("att_chat_output", ({
"The chief screams OGA BOGA!\n"
}) );
}
