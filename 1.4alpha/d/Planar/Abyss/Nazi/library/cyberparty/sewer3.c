/*
** File: /u/n/nsd/library/cyberparty/sewer3.c
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
    set( "short", "A rotten sewer" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
The sewer continues to the west. The chirping sound
of rats is all along the way. The walls are neglected
and the smell is awful.
EndText
    );
    set( "exits", ([
      "west" : POOL+"sewer4.c",
      "east" : POOL+"sewer2.c",
    ]) );
    set( "item_desc", ([
      "walls" : "Neglected walls...\n",
      "smell" : "What a dumb ass, you can't see the smell but SMELL it!\n",
      "organic waste" : "Simply shit!!  Enuf said!\n",
      "waste" : "Simply shit!!  Enuf said!\n",
      "sewer" : "Sigh... Just look around, dumb ass!!!!\n",
      "sound" : "Definately you're a moron. It's easier if you just LISTEN.\n",
    ]) );

    set("smell", "Smells like shit in here, you may want to puke.\n");
    set("listen", "An annoying loud chirping of rats deafens you...\n");

}

void reset() {
    object r1, r2, r3;

    if (!present("sewer rat", this_object() )) {
	r1 = clone_object(NAZI_MON+"mudrat3.c");
	r1->move(this_object() );

	r2 = clone_object(NAZI_MON+"mudrat3.c");
	r2->move(this_object() );

	r3 = clone_object(NAZI_MON+"mudrat3.c");
	r3->move(this_object() );

    }

}

/* EOF */
