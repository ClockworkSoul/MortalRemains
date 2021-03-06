#include <mudlib.h>
#include "garden.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 0);
    set ("area_type", ([
      "black" : 2,
    ]) );
    set ("short", "Lost in the Labyrinth of Woe");
    set( "long", @EndText
You are in a huge labyrinth of twisty little corridors and passages.
With every step you feel ever more lost. The very walls themselves
seem to shift and change.
EndText
    );
    set( "exits", ([
      "down" : MAZE+"/maze4.c",
      "east" : MAZE+"/maze3.c",
      "south" : MAZE+"/maze1.c",
    ]) );
    set ("exit_suppress", ([
    ]) );

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
