#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "Dining Room" );
    set( "long", @EndText
A long elegant dining table dominates this room covered with a fine
tablecloth, which is adorned with gold threads and pictures of hunting
scenes and the large feasts that usually accompany a successful catch.
Candles, are used to light the room, however you notice that they stay
lighted without the use of fire. This makes a statement about the powerful
mage that resides here.

EndText
    );
    
    set( "exits", ([
      "northwest" : N_ROOM+"room12.c",
    ]) );
}
