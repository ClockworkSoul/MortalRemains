#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "blood");
    set( "short", "House of the Mage");
    set( "long",@EndText
As you enter this nondescript room, words begin to flow into your mind:        
    Wish for love, wish for life.
    All this power, sharper then a knife.
    Silver strands, performing commands,
    Waiting here, and the masters fear.
    Rising high, with glorious wings
    Filling out, the call of the rings.
    Mortal eyes, peer through dark
    Asking for power, to perform the will, of some dark deed.
    Shallow waters, granting passages on a string of fate.
    Lines upon lines of silver strands, 
    Waiting and waiting, for those evil, commands.
EndText
);
    set( "exits", ([
"north" : N_ROOM+"room6.c",
"west" : N_ROOM+"stair2.c",
"east" : N_ROOM+"room11.c",
    ]) );
    set( "item_desc", ([
    ]) );
}


