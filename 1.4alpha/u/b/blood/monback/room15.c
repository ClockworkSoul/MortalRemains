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
    set( "short", "Meditation Chamber" );
    set( "long", @EndText
A deafening silence assaults your senses as you enter this room. A soft
ambient light resonates from every part of the room. Lush carpeting and soft
mats cover the floor and walls, and the ceiling depicts a star specked sky
with voids as black as the night in between.

EndText
    );
    set("item_desc",([
        "mats" : "The mats have a very hard surface, with soft padding to
prevent injury.\n",
    ]) );
       
    set( "exits", ([
         "south" : N_ROOM+"room8.c",
    ]) );
}   
