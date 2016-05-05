// Based off:(elixir.c) An elixir of healing.
// Written by Mobydick, 11-20-92.

#include <mudlib.h>
#include <where.h>

inherit OBJECT ;

void create() {
	set ("short", "a crack pipe") ;
	set ("long", "A small pipe with a small amount of crack left in it.\n");
	set ("id", ({ "crack", "pipe" }) ) ;
	set ("mass", 1) ;
        set ("value", 100);
}
void init() {
	add_action ("smoke", "smoke") ;
}
int smoke (string str) {

	int res, max, sickness;

	if (!str || !id(str)) {
		notify_fail ("What would you like to smoke?\n") ;
		return 0 ;
	}
	write ("You smoke the crack from the old pipe.\n"+
	"After the last puff, the pipe just disinergrates!\n") ;
	res = this_player()->query("hit_points") ;
	max = this_player()->query("max_hp") ;
	sickness = 15 ;
        res = res - sickness ;
	if (res<16) res = 1 ;
	this_player()->set("hit_points", res) ;
	remove() ;
	return 1 ;
}
