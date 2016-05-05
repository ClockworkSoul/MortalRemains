/*
** File: /u/n/nsd/lust/suite.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set("author", "nsd");
    set( "short", "Suite Lust");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
You are in a private suite. Here you can find a Louis-XV
king-size bed covered with Red satin blankets. Only one window
allows you to look outside. To the right side of the bed, you find
a bed-side table with one drawer. To the left is a Louis-XV sofa.
A magnificent piece of art that's worth looking at.
Seems like the owner of this room is a little eccentric.
EndText
    );
    set( "item_desc", ([
      "bed" : "A Louis-XV pillar bed. It's pretty attractive,
soft and comfortable. You really want to rest on it.\n",
"window" : "A wooden french-styled window. You can see through
it and 'watch' the 'seaview'.\n",
"table" : "A bedside table with one drawer.\n",
"sofa" : "Be careful of ruining it. This antique relic is REALLY
expensive. It's beautifully crafted Renaissance-style, with
soft pads and cushions lined in Red Velvet. You don't
really want to 'sit' on it. Do you?\n",


]) );

}

void init() {
add_action("watch_seaview", "watch");
add_action("rest_on_bed", "rest");
add_action("sit_on_sofa", "sit");
add_action("whos_the_owner", "whos");
}

int watch_seaview(string str) {
if (!str || str!="seaview") {
write("Watch what?\n");
return 1;
}

say(TPN+" is watching a romantic sea view.\n");
write(wrap(
"You enjoy the magnificent sea view, and listen\n"+
"to an entrancing sound as the waves hit the sand.\n"+
"Romance is in the air...\n"));
return 1;
}

int rest_on_bed(string str) {
if (!str || str!="on bed") {
write("Rest where?\n");
return 1;
}

say(TPN+" lays down on bed and falls asleep.\n");
write(wrap(
"The matress adjusts to your anatomy as you lay down.\n"+
"It feels so comfortable you fall asleep...zzzzzzzzzz\n"));
this_player()->move_player("/d/Planar/Abyss/Nazi/library/lust/nightmare.c");  //
return 1;
}

int sit_on_sofa(string str) {
if (!str || str!="on sofa") {
write("Sit where?\n");
return 1;
}

say(TPN+" sits on sofa and feels evil.\n");
write(wrap(
"You sit on this expensive relique, and notice a strange\n"+
"change of mood. You feel like an evil emperor...\n"+
"You want to know 'whos the owner'.\n"));
return 1;
}

int whos_the_owner(string str) {

say(TPN+" questions something.\n");
write(wrap(
"This was the private suite of an evil emperor\n"+
"who got as many women as he could.\n" +
"He stole their honor and innocence. He used to kill\n"+
"them when he got what he wanted. Their souls\n"+
"still vague around the place, hungry for vengeance.\n"));
return 1;
}

