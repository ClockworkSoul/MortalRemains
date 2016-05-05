#include <mudlib.h>           
#include "../defs.h"

inherit ROOM;

void create() {
    seteuid(getuid());
    set("light", 1);
    set( "short", "The Petting Zoo." );
    set( "long", @ENDLONG
You are in a small petting zoo.
ENDLONG
    );
    set( "exits", ([
      //"north" : "/u/c/chronos/workroom", 
      "north" : "/d/Prime/Central/room/zooent.c",
      "south" : ROOMS(zoo4),
    ]) );
    set("item_desc",
      ([
    ]) ) ;
    set("objects", ([
      "zookeeper" : MON(zookeeper),
      "child" : MON(child),
      "monkey" : MON(monkey),
      "kitten" : MON(kitten),
    ]) );
    ::create();
}


void init() {
    add_action("pet", "pet") ;
}

int pet() {
    write("You feel a strong urge to kill everything around you.\n");
    return 1;
}

int enter(string str) {
    if (!str) {
	write("Enter what?\n");
	return 1;
    }

    write("You enter the portal, and end up... elsewhere.\n");
    say(TPN+" enters the green portal, and dissapears.\n");
    TP->move("/d/Outer/Sigil/mainst1");
    say(TPN+" appears in a flash of green light!.\n");
    return 1;
}
