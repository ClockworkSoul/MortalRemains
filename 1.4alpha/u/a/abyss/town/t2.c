#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Northern Bayside Road" );
    set( "long", @EndText
As you continue on you can make out some houses to your west.  They
are very elegantly built houses.  You see a bank to your east.
EndText
    );
    set( "exits", ([
     "west"  :  "/u/a/abyss/town/houses.c",
     "east"  :  "/u/a/abyss/town/bank.c",
     "north"  :  "/u/a/abyss/town/t1.c",
     "south"  :  "/u/a/abyss/town/t3.c",
    ]) );
}
