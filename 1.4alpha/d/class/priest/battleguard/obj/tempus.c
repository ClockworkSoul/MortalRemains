
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Avatar of Tempus") ;
	set ("long", "A powerful warrior in dark crimson plate armor.\n") ;
	set ("id", ({ "tempus", "avatar"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("tempus") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("tempus") ;
	set ("stat/constitution", 25);
	set ("stat/strength", 25);
	set ("stat/charisma", 19);
	set ("stat/intelligence", 20);
	set ("stat/dexterity", 19);
	set ("stat/wisdom", 18);
	set_level(60);
	set_size(12);
	set("level", 60);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Long Blades", 5, "Strength") ;
	set_skill("Two Handed Style", 2, "Strength");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	ob1 = clone_object ("/d/class/priest/battleguard/obj/avatarsword.c") ;
    ob1 -> move (this_object()) ;
   	ob2 = clone_object ("/d/class/priest/battleguard/obj/avatarplate.c") ;
    ob2 -> move (this_object()) ;
   	}
void init () {
::init();
command("wield sword");
command("equip armor");
}
