#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Hoss' house" );
    set( "long", @EndText
This is Hoss' personalized apartment.  This cost him 10k gold... so what ever..
EndText
    );
    set( "exits", ([
     "entrance"  :"/u/a/abyss/town/houses.c",
    ]) );
}
