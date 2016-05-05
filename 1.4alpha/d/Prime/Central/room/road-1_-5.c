inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
   set("short", "An unmarked road.") ;
    set("long", @EndText
The road here gets becomes narrower and unlit as you approach a bend to
the southwest, where there is a large building. It becomes foggier here,
closer to the sea, making it easier to see the errie yellow light 
surrounding the distant brick building. To the south, through an aged 
chain-link fence, is an overgrown vacant lot, the gate to which is chained
and padlocked.
EndText
    );
    set("exits", ([
      "east" : M_ROOM+"road0_-5.c",
      "south" : M_ROOM+"lot01.c",
      "southwest" : M_ROOM+"road-2_-6.c"
    ]) );
    set("item_desc", ([
      "fence" : wrap("The fence is quite old and falling over in places. "+
	"The gate is locked, and the fence is topped with barbed wire."),
      "gate" : "It has been sealed by a thick chain and a large padlock.\n",
      "padlock" : "In contrast to the gate, the lock is shiny and new.\n",
      "fog" : "It grows thicker towards the south.\n",
      "building" : "It looks like it may be a prison. Maybe a high school.\n",
      "lot" : "It is vacant, and overgrown with weeds.\nThere appears to be "+
      "a small ramshackle structure within.\n",
      "weeds" : wrap("Mostly grasses and shrubs. A couple small trees "+
	"have also taken root."),
      "structure" : "It appears somebody lives there.\n",
    ]) );
    set("smell", ([
      "default" : wrap("You can detect faint traces of salty sea air and "+
	"decomposing organic material."),
    ]) );
    set("pre_exit_func", ([
      "south" : "south_func",
    ]) );
   ::create() ;
   reset() ; 
}        

void init() {
    add_action("climb_func", "climb");
    add_action("lock_func", "unlock");
    add_action("lock_func", "lock");
}               

int lock_func(string str) {
    if (!str) return 0;

    if (strsrch(str, "padlock") != -1) {
	write("The lock mechanism is too complex for you to affect.\n");
	return 1;
    } else {
	return 0;
    }
}

int south_func() {
    write("The gate is chained and padlocked.\n");
    return 1;
}

int climb_func() {
    write("The barbed wire would surely tear you apart.\n");
    return 1;
}

/* EOF */
