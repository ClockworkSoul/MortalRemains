#include "../cy.h"

#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

int found = 0;

void create()
{
    ::create();//<- gets all the information from the original create()
    seteuid( getuid());
    set("forbidden", 1);
    set("author", "cyanide");
    set( "light", 1 );
    set("short", "Cave Entrance");
    set( "long", @EndText
You are standing in a small clearing before the entrance to a
cave.  The cave entrance is covered by a large iron grate.
EndText
    );
    set( "exits", ([
      "down" : MAIN+"/hallway2.c",
      "north" : AREA1("a1pass01.c"),
    ]) );
    set ("exit_msg", ([
    ]) );
    create_door("down","up","A rusty iron grate","locked",
      "rus_key", 30);
}

void init() {
    add_action("search", "search");
}

int search (string str) {
    object key;

    if (str=="clearing" && !found) {
	write("You find an old key in the dust!\n");
	key = clone_object(OBJ+"/rus_key.c");
	key->move(TP);
	found = 1;
	return 1;
    }

    return 0;
}
