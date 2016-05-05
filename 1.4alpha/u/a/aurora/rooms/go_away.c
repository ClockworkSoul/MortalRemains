
// This file was created by Aurora
// For Circle  Wed Oct 26 15:51:51 1994
// Please do not remove this header file.

#include <std.h>
inherit ROOM;

	string name;

void create()  {
	::create();
	set_property( "indoors", 1 );
	set_property("light",0);
	set_short("In a box");
	set("long", @LONGTEXT
You're sitting inside a tiny box.
The cardboard walls seem really
really close to you, and you 
feel that after too long, your
legs are gonna cramp!  But this
is a good place to hide away from 
the world for a bit.
LONGTEXT
     );
	set_exits( ([
		"out" : "/wizards/aurora/rooms/closet.c",
        ]) );
        }         
 
 
void init() 
        {
        ::init();
		name = (string)this_player()->query_name();
switch(name) {
	case "aurora": write("You go into hiding as you squeeze into the box.");break;
	case "monk": write("Heya.");break;
	default: this_player()->move_player("/wizards/aurora/workroom.c");
        }
}
