

#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short" , "Entrance to a Cave" );
    set( "long", @EndText
You are in the wide open cave entrance in the hillside. This main room
seem very clean and is well lit by sunlight filtering through the force
field to the south. In the rock wall near the force field, there is a
rtinal scanner plate much like the one on the outside of the cavern. There
are three openings in the cavern walls leading to rooms beyond this one.
EndText
    );

set("item_desc", ([   
"force field" : "The shimmering force field seems to be the only\n"+
"way to get into the opening where the stream seems to flow.\n",
"plate" : "Upon closer inspection it appears to be a retinal scanner.\n",
"scanner" : "A retinal scanner. If only you had the head of someone\n"+
"with access.\n",
]) );

    set( "exits", ([
"force_field" : KYRIE+"kyrie3.c",
"east" : KYRIE+"kyrie6.c",
"west" : KYRIE+"kyrie5.c",
"north" : KYRIE+"kyrie7.c",
    ]) );
create_door("force_field", "up","A shimmering force field.", "locked", "Head 
of Dark Elf", 25);
}
