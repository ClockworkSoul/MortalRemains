/*
** Many thanks to Nsd who helped me get the monsters to work
** properly. She did an amazing job teaching me code!
*/

#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","shallar");
    set("short","Pepperland");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
You have come to the edge of Pepperland, near the woods. There is a 
place for muscians to set up and play but that has been destroyed.
There are also some large words lying about that were damaged during the 
battle with the Blue Meanies.
EndText
    );
    set( "exits", ([
      "east":INS_ROOM+"cave12.c",
    ]) );

set("item_desc",([
"woods":"Very dark and scary. It must be where the meanies came from.\n",
"words":"Giant words that were damamged during the attack. It looks like \n"+
"one of them was LOVE and the other KNOW. \n",
"place":"An outdoor stage destroyed during the initial attack.\n",
]));
reset();
}

void reset(){
    object jan, ani, zoot, floyd, teeth;

if(!present("jan") && !present("ani") && !present("zoot") && !present ("floyd") && !present("teeth")){
	jan = clone_object(INS_MON+"janice.c");
	jan->move(this_object());
	ani = clone_object(INS_MON+"animal.c");
	ani->move(this_object());
	zoot = clone_object(INS_MON+"zoot.c");
	zoot->move(this_object());
	floyd = clone_object(INS_MON+"floyd.c");
	floyd->move(this_object());
	teeth = clone_object(INS_MON+"teeth.c");
	teeth->move(this_object());

    }
}
