// A cave with a pile of coins in it.
// Mosty for texture. It rewards players who explore, though.

#include <mudlib.h>

inherit ROOM ;

void create() {
	seteuid(getuid()) ;
	::create();
        set ("light", 1") ;
        set ("long", @BiteMe
You are in the cavern where the mighty dragon Bazz once lived.
Here Sir Foo fought ans slew him. most of his treasure trove is 
gone now, but you still might find a few valuable coins tucked away.
BiteMe
);
	set ("short", "Bazz's cave") ;
	set ("objects", ([ "sword" : "/obj/light_sword" ]) ) ;
	reset() ;
	set ("exits", ([
		"north" : "/d/Fooland/fissure"
	]) ) ;
}

void reset() {

	object ob ;

	::reset() ;
	if (present("coins", this_object())) return ;
	ob = clone_object("/std/coins") ;
        if (random(2)) {
                ob->set_type("gold") ;
                ob->set_number(60) ;
        } else {
                ob->set_type ("platinum") ;
                ob->set_number(10) ;
                ob->set_number(10) ;
        }
        ob->move(this_object()) ;
}
