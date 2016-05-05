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
You have entered the house of the famed mage Prectorian. This room is
supported by large pillars formed from a yellowish stone that looks as if
it was polished many many times by dedicated hands. A tall mirror stands
to the left of the north exit, and a fountain stands tall in the center of
the room. If the rest of the house is as nice as this main entrance, this
mage must have been quite wealthy.
EndText
    );
    set( "exits", ([
      "north" : N_ROOM+"room2.c",
      "south" : N_ROOM+"?",
    ]) );
    set( "item_desc", ([
      "fountain" : wrap("The fountain has the form of a large dragon with "+
	"water spouting from its large open mouth, falling down in "+
	"between the splayed claws of the huge and horribly "+
	"beautiful beast."),
      "pillars" : wrap("They are formed from a yellowish stone that looks "+
	"as if it was polished many many times by dedicated hands."),
    ]) );
}

/* EOF */
