inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", "An unmarked road");
    set("long", @EndText
The cracked and broken asphalt pathway turns to the south here, and passes
another chainlink fence to the north and west. A large red brick building,
bathed in eerie yellow foglights beind it, through a gate to the northwest.
A vacant lot is behind yet another chain link fence to your east. There is
a sign on the fence next to the northwestern gate. From the south, you can
hear the distant sounds of ships, and foggy air carries the scent of sea
salt.
EndText
    );
    set("exits", ([
      "northwest" : M_ROOM+"HS_X",
      "south" : M_ROOM+"wharf/wharf3.c",
      "northeast" : M_ROOM+"road-1_-5.c"
    ]) );
    set("item_desc", ([
      "sign" : "It reads: Decatur High School.\n",
      "fence" : wrap("Both fences are quite old and falling over in places. "+
	"You can enter the western area to the northwest, but the gate "+
	"past the eastern fence is furth northeast. Both are topped with "+
	"barbed wire."),
      "gate" : "It has been sealed by a thick chain and a large padlock.\n",
      "padlock" : "In contrast to the gate, the lock is shiny and new.\n",
      "fog" : "It grows thicker towards the south.\n",
      "building" : "It looks like it may be a prison. Maybe a high school.\n"+
      "Maybe you could read the sign next to the gate?\n",
      "lot" : "It is vacant, and overgrown with weeds.\nThere appears to be "+
      "a small ramshackle structure within.\n",
      "weeds" : wrap("Mostly grasses and shrubs. A couple small trees "+
	"have also taken root."),
      "structure" : "It appears somebody lives there.\n",
    ]) );
    set("smell", ([
      "default" : wrap("You smell salty sea air and stench decomposing "+
	"organic material coming from the water to the south."),
    ]) );
    set("pre_exit_func", ([
      "north" : "block_func",

      // TEMP
      "northwest" : "block_func",
    ]) );
    ::create() ;
    reset() ; 
}

void init() {
    add_action("climb_func", "climb");
    add_action("lock_func", "unlock");
    add_action("lock_func", "lock");
    add_action("read_func", "read");
}               

int read_func( string str ) {
    if (str=="sign") {
	write("It reads: "+CITY_NAME+" High School.\n");
    } else {
	write("Read what? The sign?\n");
    }
    return 1;
}

int lock_func(string str) {
    if (strsrch(str, "padlock") != -1) {
	write("The lock mechanism is too complex for you to affect.\n");
	return 1;
    } else {
	return 0;
    }
}

int south_func() {
    if (!wizardp(TP)) {
	write("An \"UNDER CONSTRUCTON\" sign blocks your way.\n");
	return 1;
    } else {
	write("[WIZARD NOTICE] This area is under construction.\n");
    }
}

int block_func() {
    write("The gate is chained and padlocked.\n");
    return 1;
}

int climb_func() {
    write("The barbed wire would surely tear you apart.\n");
    return 1;
}

void reset() {
    if (sizeof(children(TOWNSFOLK))<12) {
	clone_object(TOWNSFOLK)->move(TO) ;
    }
    ::reset() ;
} 
//EOF
