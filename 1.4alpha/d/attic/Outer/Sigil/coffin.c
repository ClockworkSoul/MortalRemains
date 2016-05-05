/*
** File:  coffin.c
** The secret entrance to Cyanide;s necromancers guild.
** Idea credit:  Megaweapon
** Credits:
**    26 Jun 98   Cyanide created the file.
*/

#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

object outside = children(SIGIL + "mortuary.c")[0];

void create() {
    ::create();
    seteuid(getuid());
    set ("light", "@@query_light") ;
    set ("long", "@@query_long");
    set ("short", "In a coffin") ;
    set("exit_suppress", ([]) );
    set("item_desc", ([
    ]) );
    set("smell", "It smells like the inside of a coffin.\n");
}

void init() {
    outside = find_object_or_load(SIGIL + "mortuary.c");
    outside = children(SIGIL + "mortuary.c")[0];
    add_action("open", "open");
    add_action("close", "close");
    add_action("close", "shut");
    add_action("out", "out");
}

int query_light() { return outside->query_open(); }

int out() {
    if (!outside->query_open()) {
	write("The coffin is still closed.\n");
	return 1;
    }

    write("You climb out of the coffin.\n");
    TP->move_player(outside, "SNEAK");
    say(TPN+" climbs out of the coffin.\n");

    return 1;
}

int go(string str) {
    if (str=="out") {
	return out();
    }

    return 0;
}

string query_long() {
    string str = "You are inside a padded, silk-lined "+
    "coffin. The lid is "+ (query_light() ? "open, and it "+
      "is dark." : "closed.");

    str += "\n        The only obvious exit is out.";

    return wrap(str);
}

int open(string str) {
    if (str=="coffin" || str=="lid") {
	if (!outside->open_func())
	    write("The coffin is already open.\n");
	else {
	    write("You open the coffin, and light streams in.\n");
	    tell_room(outside, "The coffin creaks open.\n");
	}
	return 1;
    }
    return 0;
}

int close(string str) {
    if (str=="coffin" || str=="lid") {
	if (!outside->close_func())
	    write("The coffin is already closed.\n");
	else {
	    write("You close the coffin, and darkness "+
	      "covers you.\n");
	    tell_room(outside, "A hand reaches up and "+
	      "closes the coffin from the inside.\n");
	}
	return 1;
    }
    return 0;
}
