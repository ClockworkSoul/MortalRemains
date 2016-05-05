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
set("short","cave entrance");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
You have reached the top of the path. There is an opening in a group
of rocks and a sign placed near it. The crazy noises
echo off of the rocks.
EndText
    );
    set( "exits", ([
"east":INS_ROOM+"path2.c",
"cave":INS_ROOM+"cave1.c",
    ]) );

set ("item_desc",([
"rocks":"The rocks form the opening to the cave. You might be able\n"+
"to climb up and look inside.\n",
"sign":"This sign was created with bright crayons. Try reading it.\n",
]) );

    set("objects",([
"chumley":INS_MON+"chum.c",
    ]) );
reset();

}

void init() {
    add_action("read_sign","read");
    add_action("climb_rocks","climb");
}

int read_sign(string str) {
    if (!str || str!="sign") {
	write ("Read what?\n");
	return 1;
    }

say (TPN+ " bends over to read the sign and recoils with suprise!\n");
    write (@EndText

____________________________________________
|                                           |
|*******************************************|
|                                           |
|            ABYDUN HOPEE AWL               |
|            YEH HOM NTER HEIR!!!           |
|                                           |
|*******************************************|
|                                           |
____________________________________________
               |           |
               |           |
               |           |
               |           |
EndText);
    return 1;
}

int climb_rocks (string str) {
    if(!str || str!="rocks") {
	write ("You can't find your way up. Perhaps if you used the rocks?\n");
	return 1;
    }

    say (TPN + "climbs up the rocks and peers into the caves to see what the comotion is.\n");
    write (wrap("You climb up the rocks to the top of the cave.\n"+
	"You peer down an opening in the roof and see a bunch \n"+
	"of strange creatures milling about. Your curiosity is piqued.\n"));
    return 1;
}
