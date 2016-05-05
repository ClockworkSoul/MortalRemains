/*
** The lobby of the mage guildhall in Sigil.
** Cyanide 23 Sep 97
*/

#include "guildhall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("short", "Main Lobby of Magicka University"); 
    set( "long", wrap("You are in the opulant lobby of the Magicka "+
	"University - the center for magical learning in the city. The "+
	"black granite floors are polished to a perfect shine, and "+
	"great tapestries hang on the walls dedicated to great wizards "+
	"all over the multiverse. Great silver archways "+
	"lead in the four cardinal directions: the Hall of Learning to the east, "+
	"the Great Library to the south, the Wizard's Lounge to the north, and "+
	"back to the city to the west."
      ));
    set( "exits", ([
      "north" : RM_MAGES+"m_boardrm.c",
      "west" : "/d/Prime/Central/room/road0_2.c",
      "east" : RM_MAGES+"mage_guild",
      "south" : RM_MAGES+"m_profhall.c",
    ]) );
}
