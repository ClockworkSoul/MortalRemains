#include "main.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set ("author", " -{ CYANIDE }- ");
    set("forbidden", 1);
    set ("light", 0);
    set ("short", "Mirror Room" );
    set( "long", @EndText
You are in a moderately sized room carved directly from the stone.
The only significant feature here is a huge mirror, covering the
entire southern wall.
EndText
    );
    set( "exits", ([
      "west" : GARDEN+"/maze1.c",
    ]) );
    set ("item_desc", ([
      "mirror" : "There is an ugly person staring back at you.\n"
    ]) );
}

void init () {
    add_action("mirrort","touch");
}

int mirrort(string str) {
    if (str!="mirror") {
	notify_fail("Touch what?\n");
	return 0;
    }

    say (
      "The ground rumbles a bit, and "
      +this_player()->query("cap_name")+" dissapears in a \n"+
      "huge implosion and burst of darkness!\n");
    write (
      "There is a deep rumbling in the distance.\n"+
      "Your surroundings seem to have changed subtly.\n");
    this_player()->move(MAIN+"/mirror1.c");
    return 1;
}
