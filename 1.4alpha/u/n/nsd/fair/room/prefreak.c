/*
** File: prefreak.c
* Author: Lady Nsd (Cyanide helped a bit)
*/

#include <config.h>
#include <mudlib.h>
#include "fair.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "To the Freak Show");
    set( "long",@EndText
This is the entrance to the freak show. Here you'll see the most
rare, weird, and depressing freaks in the history of fairs.
You must be strong to bare what you're about to see. Make sure
to have your ticket in order to get in. If you don't have a ticket,
go to the ticket dispenser booth.
EndText);
    set( "exits", ([
      "west" : "?",
      "east" : "?",
      "enter" : FAIR_ROOM+"freak1.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "guy" : FAIR_MON+"tkfreak.c",
    ]) );
    set("pre_exit_func", ([
      "enter" : "guy"
    ]) );
    reset();
}
// Cyanide made this for me :)   :
/*
int guy() {
    if(present("guy", TO)) {
	write("Ticket guy says [to you]: Sorry, you don't have a ticket.\n");
	say("Ticket guy says [to "+TPN+"]: Sorry, you don't have a ticket.\n");
	return 1;
    } else {
	return 0;
    }
}
*/

int guy() {
    if (present("guy", TO)) {
	object ticket = present("ticket", TP);
	if(ticket) {
	    write("The ticket guy takes your ticket and lets you in.\n");
	    say("The ticket guy accepts "+TPN+"'s ticket.\n");
	    ticket->remove();
	} else {
	    write("Ticket guy says [to you]: Sorry, you don't have a ticket.\n");
	    say("Ticket guy says [to "+TPN+"]: Sorry, you don't have a ticket.\n");
	    return 1;
	}
    }

    return 0;
}

/* EOF */
