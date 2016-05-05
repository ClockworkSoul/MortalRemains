// Written by Mobydick, 11-20-92.

#include <mudlib.h>
#include <sewers.h>

#define HEALING 15

inherit OBJECT ;

void create() {
     seteuid(getuid());
     set("author", "cattt");
     set("id", ({ "mug","fine ale","ale" }) );
     set("short", "a mug of fine ale");
     set("long", @End
A mug of very fine ale.  The cup is half full as if someone else found it
and had to drink some themselves.
End
  );
}

void init() {
	add_action ("drink", "drink") ;
}

int drink (string str) {

     int res, max ;
     
     if (!str) {
	notify_fail ("What would you like to drink?\n") ;
	return 0 ;
	}
     if (str=="ale" || str=="mug") {

        write ("You drink the fine ale and it tastes really good.\n");
        say(wrap(TPN+" drinks "+objective(TP->query("gender"))+" fine "+
            "ale and it makes you want some.") );
	write ("As you drink the last drop, the mug vanishes in a puff of smoke!\n") ;
	res = this_player()->query("hit_points") ;
	max = this_player()->query("max_hp") ;
	res = res + HEALING ;
	if (res>max) res=max ;
	this_player()->set("hit_points", res) ;
	remove() ;
	return 1 ;
}}
