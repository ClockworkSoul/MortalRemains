/*
** File: /u/n/nsd/workroom.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void init() {
    ::init();
    add_action("watch_seaview", "watch");
    add_action("rest_on_bed", "rest");
    add_action("sit_on_sofa", "sit");
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
	"The mattress adjusts to your anatomy as you lay down.\n"+
	"It feels so comfortable you fall asleep...zzzzzzzzz\n"));
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
	"change of mood. You have lustful thoughts...\n"));
    return 1;
}
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "BedRoom");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "c_long", @EndLong
You have entered NSD's PRIVATE suite. Here you can find a Louis-XV
king-size bed covered with Red satin blankets. Only one window
allows you to look outside. To the right side of the bed, you find
a bed-side table with one drawer. To the left is a Louis-XV sofa.
EndLong
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
      "south" : "/u/n/nsd/pool.c",
      "east" : "/u/n/nsd/bathroom.c",
    ]) );
    set( "item_desc", ([
      "bed" : "A  Louis-XV antique pillar bed. It's attractive,\n"+
      "soft and comfortable. You really want to rest on it.\n",
      "window" : "A wooden french-styled window. You can see through\n"+
      "it and watch the sea view. You feel romantic...\n",
      "sofa" : "Be careful of ruining it. This antique relic is REALLY\n"+
      "expensive. It's beautifully crafted Renaissance-style, with\n"+
      "soft pads and cushions lined in Red Velvet. Isn't NSD too\n"+
      "eccentric?\n",
      "jar" : "A crystal jar with a single rose and a label.\n",
      "rose" : "It's a dry and wilted rose. Although it has\n"+
      "plenty of water, the rose is dead. Just a reflextion\n"+
      "of it's owner's state of mind...\n"+
      "The petals are pointing at a label.\n",
      "label" : "The label has water stains that seem like tears.\n"+
      "It's readable...\n",

    ]) );
    set("objects", ([
      "table" : "/u/n/nsd/obj/table.c",
    ]) );
    reset ();

}


