/*
** File: /u/n/nsd/bathroom.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** Special thanks: To my beloved Nemar for helping me code the actions.
*/

#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void init() {
    ::init();
    add_action("fill_tub", "fill");
    add_action("take_shower", "take");
    add_action("enter_tub", "enter");
}

int fill_tub(string str) {
    if (!str || str!="tub") {
	write("Fill what?\n");
	return 1;
    }

    say(TPN+" fills the tub with warm water and bubbles.\n");
    write(wrap(
	"You fill the tub with warm water and bubbles...you\n"+
	"want to enter there.\n"));
    return 1;
}
int enter_tub(string str) {
    if(!str || str!="tub") {
	write("Enter what?\n");
	return 1;
    }

    say(TPN+" enters the tub, sits, and feels relaxed.\n");
    write(wrap(
	"As you enter the tub, the bubbles tickle your naked body.\n"+
	"All the tension is gone. You feel relaxed...\n"));
    return 1;
}

int take_shower(string str) {
    if (!str || str!="shower") {
	write("Take what?\n");
	return 1;
    }

    say(TPN+" takes a soothing warm shower and feels brand new.\n");
    write(wrap(
	"You enjoy a refreshing and soothing warm shower. It automatically\n"+
	"adjusts itself to a pleasing temperature, making you feel\n"+
	"brand new.\n"));
    return 1;
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Bathroom");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("c_long", @EndLong
This is the personal bathroom of the suite. It has a 
seashell-shaped tub and victorian ornaments. Smells like
ocean breeze. Every ornament in this bathroom is ivory
and burgundy. A big oval mirror is hanging on the wall.
EndLong
    );
    set( "exits", ([
      "west" : "/u/n/nsd/workroom.c",
    ]) );
    set( "item_desc", ([
      "tub" : wrap(
	"Big enough for two persons. It has a shower included.\n"+
	"you can either get a warm shower, or fill the tub."),

      "mirror" : wrap(
	"An oval victorian mirror. You can see your good or bad\n"+
	"side reflected in it."),

      "shower" : "A shower that will adjust it's temperature automatically\n"+
      "when you 'take' your 'shower'! ;-)  \n",
    ]) );
    set("objects", ([
      "cabinet" : "/u/n/nsd/obj/wcabinet.c",
    ]) );
    reset();
}

