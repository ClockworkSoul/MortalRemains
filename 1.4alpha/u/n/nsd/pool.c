/*
** File: /u/n/nsd/pool.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit PRIVATE_ROOM;

void init() {
    ::init();
    add_action("jump_board", "jump");
    add_action("climb_down", "climb");
    add_action("climbout", "climbout");
    add_action("swim", "swim");
    add_action("do_float", "do");
    add_action("search_sockets", "search");
    add_action("portal", "portal");
}

int jump_board(string str) {
    if (!str || str!="board") {
	write("Jump what?\n");
	return 1;
    }
    say(TPN+ " gives an olympic jump on the diving board and"+
      " splashes into the water...WOO WOO!!!\n");
    write(wrap(
	"You jump on the diving board and splash into the "+
	"water... ouch! That must hurt.\n"));
    return 1;
}

int climb_down(string str) {
    if(!str) {
	write("Climb where?\n");
	return 1;
    }

    if (str=="down") {
	say(TPN+" climbs down the ladder, and gets in the pool.\n");
	write(
	  "As you climb down the ladder, the warm water covers"+
	  "your skin.\n Ahhhh... delicious!\n");
    }
    if (str=="up" || str=="out") {
	say(TPN+" Climbs up the ladder and exits from pool.\n");
	write(
	  "You climb up the ladder and exit from pool.\n"+
	  "You spill drops of water all around the border.\n");
    }
    return 1;
}

int climbout (string str) {
    return 1;
}

int swim(string str) {
    say(TPN+" swims in the pool and teases you to do the same.\n");
    write(wrap(
	"You swim in that magnificent warm water that relaxes\n"+
	"your body immediately. Right now, you're the envy\n"+
	"of those who are watching\n"));
    return 1;
}

int do_float(string str) {
    if (!str || str!="float") {
	write("Do what?\n");
	return 1;
    }

    say(TPN+" floats like a swan.\n");
    write(wrap(
	"You float on that water that has soothe your tensions and\n"+
	"your limbs... You don't want to leave, not yet...\n"));
    return 1;
}
int search_sockets(string str) {
    if (!str || str!="sockets") {
	write("Search what?\n");
	return 1;
    }
    say(TPN+" found something interesting on the frescoes!\n");
    write(wrap(
	"You search the empty eye-sockets of the angel and\n"+
	"find a button that opens a portal to the past. A portal\n"+
	"to another mud reality. You decide if you stay here, or\n"+
	"leave through the 'portal'.\n"));
    return 1;
}
int portal(string str) {
    say(TPN+" fades from view...\n");
    write(wrap(
	"You give a voyage to a stolen piece of NK. You're now in a\n"+
	"medieval dimension...\n"));
    this_player()->move_player(ARV_ROOM+"princess_chamber.c");
    say(TPN+" appears whole, and somewhat confused...\n");
    return 1;
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "The Relaxing Room" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("c_long", @EndLong
You have entered the Relaxing Room. Here you find a large
pool in the center of it. The pool has the shape of a
giant seashell. The walls surrounding it have frescoes
imitating some Michaelangelo's paintings. You feel
tempted to swim a little.
EndLong
    );
    set( "exits", ([
      "north" : "/u/n/nsd/workroom.c",
    ]) );
    set( "item_desc", ([
      "pool" : "A swimming pool. Big enough to make a party with all\n"+
      "your friends. Seems relaxing. A ladder in front of you leads\n"+
      "you into it. A diving board is at the other extreme of the pool.\n",
      "water" : "The water is comfortably warm. You feel the urge to swim...\n",
      "walls" : "The walls have 'frescoes'.\n",
      "frescoes" : "Antique styled plaster paintings of angels. Definitely\n"+
      "an expensive work of art. The angels seem to observe you. \n",
      "ladder" : "A pool ladder. You can either 'climb down' to get into\n"+
      "the pool, or 'climb up' to get out.\n",
      "board" : "A nice olympic diving board. Try 'jump board' to use it.\n",
      "angels" : "Cherubs mostly. One of them has empty eye sockets.\n"+
      "'Search' the 'sockets'...\n",

    ]) );
    set("objects", ([
    ]) );
}


