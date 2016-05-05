/*
** File: entrance.c
** Author: Ragevortex
** Updated and fixed by: Nsd  (july 2000)
*/

#include <config.h>
#include <mudlib.h>
#include "mina.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Entrance to the Minotaur's lair" );
    set("author", "ragevortex");
    set( "long", @EndText
You stand in a cold metal room. There are several warnings posted
on the walls. The metal walls seem to be covered with
scratches and dents. There are stains on the floor and walls.
EndText
    );
    set( "exits", ([
      "start" : START,
      "teleporter" : MINA_ROOM+"teleporter.c",
    ]) );
    set("item_desc", ([
      "warning" : (@EndText
WARNING, DO NOT ENTER!, This leads to the lair of the
minotaurs. Also this is the realm of the TYPO KING!
Do not report!!

RE-EVALUATION OF THIS LAW:
As the queen of darkness is in charge of this area now,
feel free to report any bug, error, or typo. Don't mind
the first two lines of this message!
-Lady Nsd
P.S.
Ex coder of it was Ragevortex...
EndText),
      "warnings" : "Most of them seem unreadable but there's one warning\n"+
      "you can examine here.\n",
      "stains" : "Nothing but dry blood... the metal around them is rusted.\n",
      "scratches" : "Although they are solid, something was able to scratch"+
      " them.\n",
      "dents" : "They look like something was smashed rather solidly here.\n",
      "teleporter" : "A pannel on a corner that glows with crackling energy.\n"+
      " It says 'Teleporter' in flashy letters.\n",]) );
}
