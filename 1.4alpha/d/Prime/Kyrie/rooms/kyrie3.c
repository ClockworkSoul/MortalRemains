
#include <mudlib.h>
#include <config.h>
#include <kyrie.h>

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","spooner");
    set( "light", 1 );
    set("short", "Kyrie Forest Trail");

    set( "long", @EndText
You come to an end in the trail here. The stream goes into a cave
and disappears under a force field and into the hillside. In the rock
wall near the force field you see a small plate that seems to have
little light behind it. Also there's something strange about this place,
the shadows are no longer anywhere to be found.  You feel a little more
comfortable here.
EndText
    );

set("item_desc", ([
"force field" : "The shimmering force field seems to be the only\n"+
"way to get into the opening where the stream seems to flow.\n",
"plate" : "Upon closer inspection it appears to be a retinal scanner.\n",
"scanner" : "A retinal scanner. If only you had the head of someone\n"+ 
"with access.\n",
"stream" : "This stream looks very clean and cold.\n",
"hillside" :"you notice that the stream goes right into the hill here.\n",
]) );

    set( "exits", ([
"south" : KYRIE+"kyrie2.c",
"force_field" : KYRIE+"kyrie4.c",
    ]) );
create_door("force_field", "south", "A shimmering force field.", "locked", 
"Head of Dark Elf", 25);
}
