#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
   set("long", @ENDLONG
You stand on Berk Lane in the Lower Ward of Sigil, where the high-ups
of magic do their business.  To the south, you see the reknown
Mage Club, and to the west lies a magic shop.
A book store of some sort lies to the east.
ENDLONG
  ) ;
 set("short", "Berk Lane, Lower Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"mainst15.c",
	"south" : SIGIL+"magesociety.c",
	"east" : SIGIL+"partedviel.c",
	"west" : SIGIL+"friendlyfiend.c" ]));
}
