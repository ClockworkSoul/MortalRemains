/*
** File: cascade.c
** Author: Lady Nsd
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;
void create(){
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Nimph Cascade");
    set( "long", @EndText
Finally you found the cascade. You can feel the cold
waterdrops touching your skin. This is the place in which
many lovers have met for centuries. The rainbow dies in
the river, and the imponent cascade invites you to swim.
Many rocks border the river, and the cascade. The pine
trees seem to hide some secrets.
EndText);
    set( "exits", ([
      "northeast" : ARV_ROOM+"riverway4.c",
    ]) );
    set("item_desc", ([
      "rainbow" : wrap(
	"The rainbow dies in the river. Another rainbow forms\n"+
	"around the sun as you look at it. Definately a magical\n"+
	"place..."),
      "cascade" : wrap(
	"A strong cascade that stumps furiously in the river, but\n"+
	"still gentle to the skin. Many lovers and maidens have\n"+
	"taken their baths here. Behind the cascade is something\n"+
	"that seems like a cave..."),
      "cave" : wrap(
	"Not from here. You will have to 'climb' the 'rocks' in \n"+
	"order to get there..."),
      "rocks" :  wrap(
	"Giant rocks that border the cascade. Some of them seem\n"+
	"slippery, but others are dry enough to 'climb' them."),
      "river" : wrap(
	"It's down from here. To go there, you can walk all\n"+
	"the way down through the 'rockpath'. Looks really\n"+
	"inviting..."),
    ]) );
    set("listen", wrap(
	"Nothing but the imponent sound of the cascade. You hear\n"+
	"how it stumps furiously down in the river. And from time\n"+
	"to time you hear a female humming voice that echoes\n"+
	"almost inaudible, and fades away...\n"));
}
void init () {
    add_action("climb_rocks", "climb");
    add_action("rockpath", "rockpath");
}
int climb_rocks (string str) {
    write("You begin climbing all the way up through the rocks...\n");
    write("climbing...\n");
    say(TPN+" climbs all the way up through the rocks...\n");
    this_player()->move_player(ARV_ROOM+"midrockway.c");   //
    say(TPN+" has been climbing up and meets here with you.\n");
    return 1;
}
int rockpath(string str) {
    write("You decide to walk down the rock path...\n");
    say(TPN+" leaves down through the rock path...\n");
    this_player()->move_player(ARV_ROOM+"river.c");
    say(TPN+" follows you down through the rock path.\n");
    return 1;
}

/* EOF */
