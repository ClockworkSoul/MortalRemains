/*
** File: cave3.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 0 );
    set("author", "nsd");
    set("short", "Inside the cave");
    set( "long", @EndText
Here you see some carvings in the stone walls. Obviously
someone else was here first. But seems like it was long
ago. Perhaps centuries ago.  Suddenly you feel alone.
But it's not the normal loneliness, it's more like an
emptiness of the soul. You long for your beloved one.
But it's strange because you were not even thinking of
that. You're seduced by some force. There goes that
voice again...
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"cave2.c",
    ]) );
    set("item_desc", ([
      "walls" : "Solid stone walls. They have carvings engraved.\n",
      "carvings" : wrap(
	"Giving a closer look, you notice the carvings are really\n"+
	"letters. Some kind of spell carved in stone. It's readable."),
    ]) );
    set("listen", wrap(
      ));
}
void init () {
    add_action("read_carvings", "read");
}
int read_carvings (string str) {
    if (!str || str!="carvings") {
	write("What do you want to read?\n");
	return 1;
    }
    say(TPN+" reads the carvings on the wall\n");
    write(@EndText
Sorry wizzies, this wall is still under construction.
Soon there will be some interesting writing in this
wall, but meanwhile some other details
will be added to other parts of this area, so be
patient. i'm working on it all as fast as I can.
                             -The wizard
EndText);
    return 1;
}

/* EOF */
