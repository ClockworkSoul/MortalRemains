/*
** File: /u/n/nsd/library/cyberparty/sewer2.c
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
This is one of the many sewers which conducts all the
organic waste out of the city. The walls are neglected
and the smell is awful. The chirping sound of rats is
all along the way.
EndText
    );
    set( "exits", ([
      "west" : POOL+"sewer3.c",
      "up" : POOL+"sewer.c",
    ]) );
    set( "item_desc", ([
      "walls" : "Neglected walls...\n",
      "smell" : "What a dumb ass, you can't see the smell but SMELL it!\n",
      "organic waste" : "Simply shit!!  Enuf said!\n",
      "waste" : "Simply shit!!  Enuf said!\n",
      "sewer" : "Sigh... Just look around, dumb ass!!!!\n",
      "city" : "Not from here. You gotta find your way out first.\n",
      "sound" : "Definately you're a moron. It's easier if you just LISTEN.\n",
    ]) );

    set("smell", "Smells like shit in here, you may want to puke.\n");
    set("listen", "An annoying loud chirping of rats deafens you...\n");
}

/* EOF */
