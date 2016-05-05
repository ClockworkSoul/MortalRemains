
// This file was created by Aurora
// For Paradox II  Mon Oct 24 10:16:00 1994
// Please do not remove this header file.

#include <std.h>
inherit ROOM;

	string name;

void create()  {
	::create();
	set_property( "indoors", 1 );
	set_property("light",0);
	set_short("Closet");
	set("long", @LONGTEXT

This is a TINY closet.  There are clothes hanging in here, as well as boxes 
on the floor.  Though it is small, it is rather cosy and inviting.
LONGTEXT
     );
	set_items( ([
		"clothes"  :  "Various clothes hanging from hangers.",
		"boxes"  :  "Boxes of all shapes and sizes.  They actually look like they'd be comfortable to sit on.",
	]) );
	set_exits( ([
		"lounge" : "/wizards/aurora/rooms/lounge.c",
		"box" : "/wizards/aurora/rooms/go_away.c",
        ]) );
	set_invis_exits( ({"box"}) );
        }         
 
 
void init() 
        {
        ::init();
		name = (string)this_player()->query_name();
switch(name) {
	case "aurora": write("You squeeze into the closet.");break;
	case "gideon": write("The clothing parts slightly and allows you to squeeze into the closet.");break;
	default: this_player()->move_player("/wizards/aurora/workroom.c");
        }
}
