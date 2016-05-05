/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
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
    set("short","route to fairgrounds");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
You walk down the cavern & notice that it's much brighter to the south.
You feel like you are turning into Technicolor. The insane laughter from
the main hall dies down and you feel a wave of peace wash over you.
There is an old Merry Go Round here, but oddly enough, there are no
horses on it.
EndText
    );
    set("smell","It smells like a fresh day in the country, with a touch of \n"+
      "chalk dust floating in the air.\n");
    set("listen","You can hear the sounds of a caliophie farther down the passage.\n");
    set( "exits", ([
      "north" : INS_ROOM+"cave1.c",
      "south" : INS_ROOM+"cave7.c",
    ]) );
set("item_desc", ([
"merry go round":"A childnen's amusement park toy that is missing the animals. \n",
"cavern":"A long cavern connected to the main caves. It seems to go from \n" +
"black and white to color as it angles to the south. \n",
]));
}
