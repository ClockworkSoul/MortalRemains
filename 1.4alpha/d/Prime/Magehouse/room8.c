#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("objects",(["mage" : "/d/Prime/Magehouse/monsters/mage4.c"]) );
    reset();
    set( "short", "House of the Mage");
    set("author", "blood");
    set( "long",@EndText
Pain explodes through your head as you walk around this room. Warriors
from the past linger here, barely mortal. Long, shiny, and extremely well-
forged blades, armorments and other assorted battle equipment are well 
organized through out this room. Each warrior who has equipment here, died
in this room and are again preserved with unknown magics. You can hear the
glory of each battle, individually and yet, as you stand here, they all
seem to mingle into a story of triumph and grace. Battles fought for the 
needy, battles fought for honor. You feel puny and insignificant here.
Someday, perhaps you will be among these noble warriors.
EndText
    );
    set( "exits", ([
      "west" : N_ROOM+"stair3.c",
      "southwest" : N_ROOM+"room9.c",
      "north" : N_ROOM+"room15.c",
      "east" : N_ROOM+"room10.c",
    ]) );
    set( "item_desc", ([
    ]) );
    set("listen", wrap("All you can hear are the gloriius battles of the "+
	"warriors, each being constantly relived."));
}


