// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", "A Vacant Shop");
    set("long", wrap(
	"This room seems to have been partially remodelled, and "+
	"abandomed. Unused plywood lies against the wall, and blue "+
	"frayed tarps cover the floor, which is slightly newer "+
	"then the rest of this place.\nOn the far side of the room "+
	"is a large white portal, the floor around it covered "+
	"in frost and ice."
      ) );
    set("exits", ([
      "west" : M_ROOM+"road0_5.c",
    ]) );
    set("item_desc", ([
      "tarp#tarps" : "They cover the floor, apparently to "+
      "protect it.\n",
      "portal#white portal" : "You may be able to enter it?\n",
    ]) );
    ::create() ;
    reset() ; 
}

void init() {
    add_action("enter", "enter");
}

int enter( string str ) {
    write("You are blinded by a blast of icy air as you enter!\n");
    say(TPN+" enters the swirling portal!\n");
    TP->move_player("/d/Arctic/Shya/rooms/room1.c", "SNEAK");

    return 1;
}



// EOF
