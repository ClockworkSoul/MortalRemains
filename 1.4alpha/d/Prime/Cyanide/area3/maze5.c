#include "garden.h"
#include "/u/c/cyanide/debug.h"

inherit ROOM;

object thief;

void create()
{
    ::create();
    seteuid( getuid() );
    set ("author", "cyanide");
    set ("light", 0);
    set ("short", "Lost in the Labyrinth of Woe");
    set( "long", @EndText
You are in a huge labyrinth of twisty little corridors and passages.
With every step you feel ever more lost. The very walls themselves
seem to shift and change.
EndText
    );
    set( "exits", ([
      "north" : MAZE+"/maze3.c",
      "east" : MAZE+"/deadend2.c",
      "southwest" : MAZE+"/maze6.c",
    ]) );
    set ("exit_suppress", ([ ]) );

    set ("item_desc", ([
      "humm" : "hummmmmmmmmmmmmm...",
      "labyrinth" : "Cyanide says, \"Nice try, dude.\"\n",
      "corridors" : "Wouldn't that make life too easy? That's no fun!\n",
      "passages" : "Umm... they look like corridors to me...\n",
      "wall" : "The nearest wall look just like all the other walls of this maze\n",
      "maze" : "Yeah, right.\n",
      "walls" : "They seem to be made of a polished black basalt. They humm slightly.\n",
    ]) );
}

void reset() {
	::reset();
    seteuid( getuid() );
    DEBUG(MON+"/thief.c\n");
	if (!thief) {
		thief = clone_object(MON+"/thief.c");
		if (thief) thief->move(this_object());
			else DEBUG("Problem in "+base_name(TO)+"!\n");
	}
}
