
#include <mudlib.h>
inherit MONSTER ;

void create () {
	::create();
	seteuid(getuid());
	set("short", "A Gnome Guard");
	set ("long", @FEE
This is one of the guards of the Gnome City.
His tight yellow skin is pulled across his round face.
He glares at you with his bright yellow eyes.
FEE
);
	set("id", ({ "gnome" }) );
	set_level(10);
	set_size(7);
	set_name("Gnome Guard") ;
	set("gender", "male");
	set("race", "Gnome");
	set("undead", 1);
	set_name("Gnome Guard") ;
Sword - clone_object("/u/r/roadrunner/berg/weap/gssword.c");
	Short Sword->move(this_object());
	set("damage", ({ 1,4 }) );
	set("weapon_name", "fists") ;
	set_verbs( ({ "attack", "punch at", "swing at", "hit", "punch" }) ) ;
set_verbs2( ({ "attacks", "punches at", "swings at", "hits", "punches" }) ) ;
	set_verbs( ({ "attack", "punch at", "swing at", hit", "punch" }) ) ;
	enable_commands() ;
	set("natt", 1);
	arm("/u/r/roadrunner/berg/weap/gssword.c", "Gnome Short Sword") ;
}

void init() {
	command("wield axe");
}
27
