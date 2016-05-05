#include <config.h>
#include <mudlib.h>
#include "camel.h"

object maker;

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("author", "cyanide");
    set("short", "The Immortal's Hall");

    set("long", wrap(
	"You are in the Hall of Immortals, Main Lobby. "+
	"It is fairly Spartan in appearance, with highly "+
	"polished white marble floors and pillars. "+
	"To the west, is the Suggestions Room, to the "+
	"south is the Bugs and Errors Room, and to the "+
	"north is a simple metal door, leading to the "+
	"player' start location."
      ) );
    set( "exits", ([
      "north" : START,
      "west" : "/d/Ancients/rooms/suggest_rm.c",
      "south" : "/d/Ancients/rooms/bugroom.c",
    ]) );
    set ("item_desc", ([
    ]) );
    call_other("d/Ancients/obj/board.c", "foo");
    reset();
}

int receive_object(object ob) {
    if (userp(ob) && !wizardp(ob)) {
	tell_object(ob, "Sorry - immortals only.\n");
	return 0;
    }

    return 1;
}
