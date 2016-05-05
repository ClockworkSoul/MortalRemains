#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
      ::create();
    	seteuid(getuid());
  set("objects", ([
   "lissandra" : MON(lissandra),
   "#PORTAL#" : OBJ(tormeid_portal),
  ]) ) ;
	reset();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in a large courtyard in the Clerk's Ward of Sigil.
A large statue of a warrior astride a horse towers over you here.
This is purported to be the location of several portals.
ENDLONG
  );
  set("item_desc", ([
   "statue" : @ENDMSG
The statue is of a powerful warrior astride a gallant horse.  The warrior
is obviously some sort of knight, because his shield bears a crest of
an eagle on it.

An inscription on the bottom of the statue says:
          "When in distress, to the Star of the North I did look."
ENDMSG
  ,
  ]) ) ;
   set("short", "Triptic Nic'Epona.") ;
     set ("exits", ([
	"east" : SIGIL+"thistlewindst1.c" ]));

	}
