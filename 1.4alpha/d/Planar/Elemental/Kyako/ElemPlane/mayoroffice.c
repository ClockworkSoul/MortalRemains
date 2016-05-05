#include <mudlib.h>
#include "plane.h"

inherit ROOM;
inherit DOORS;

void create(){
    ::create();
    seteuid(getuid());
    set ("light", 1) ;
    set ("objects", ([ "mayor" : PLANE+"monsters/mayor" ]) );
    reset();
    set ("long", @Mayor
You are in the mayor's office.
It is decorated with the finest luxuries.
There are three windows, to the north, west, and east, with views of the ocean.
There are several impressive statues here, too.
You wonder how the mayor of a deserted island can afford all of this.
Mayor
    );
    set ("short", "Mayor's Office") ;
    set( "exits", ([
      "south"  : PLANE+"pathe2.c",
    ]) );
    create_door("south","north","An oak door","open","mayorkey",30);
}


void init(){
    add_action("norte", "go");
}

int norte(string str){
    object mon;

    if (str == "north"){
	write("You notice that the north window is open slightly.\n");
	write("Pushing on it, the window swings open and you are able\n");
	write("to climb out.\n");
	say(TPN+"pushes open the north window and climbs out.\n");
        TP->move_player(PLANE+"outwindow.c");

	mon = present("mayor", this_object());
	if (mon) 
	    mon->resetcmd();
	mon = present("statuemon", this_object());
	if (mon) mon->remove(); 
	return 1;
    }
    return 0;
}
