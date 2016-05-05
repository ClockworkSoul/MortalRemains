#include "basement.h"
#include <config.h>
#include <mudlib.h>   
    
inherit ROOM;
    
void create()
{
    ::create();
    seteuid( getuid() );
    set("objects",(["mole" : "/d/Prime/Magehouse/monsters/mole1.c",]) );
    reset();
    set( "light", 1 );         
    set("author","blood");
    set( "short", "Mole Den" );
    set( "long", @EndText
These particular rodents seem to have more culture and class than their
relations above. Larger, more comfortable passages with less twists and
turns make journey much easier on this level.
EndText
    );
    
    set( "exits", ([
      "down" : BSMNT+"mden5.c",
      "up" : BSMNT+"mden3.c",
    ]) );
}
