#include <mudlib.h>
#include "sigil.h"
inherit "/u/i/ilzarion/factionhall.c";

void create() {
     ::create();
	seteuid(getuid());
 	     set ("objects", ([ "ambar" : "/d/Outer/Sigil/monsters/ambar",
"#PORTAL#" : "/d/Outer/Sigil/items/baator_portal" ]));
	reset();
     set ("light", 1) ;
      set("faction", "Godsmen");
  set("short", "The Foundry Main Office.") ;
  set("long", @ENDLONG
You stand in the office of the Factol of the Foundry.
If you would like to join the ranks of the Godsmen, simply type join.
And if you know another Godsmen then type thier name too ex: <join ambar>
You will achieve a higher state of being faster (10% xp bonus), but
you can never be restored from death (automatic removal).
Commands: join <sponsor> , store <item> , retrieve , listing\n") ;
ENDLONG
  );
     set ("exits", ([
          	"south"	: SIGIL+"foundry.c" ]) ) ;
}
void do_ability(){

//the godsmen's ability (xp bonus) is found in body.c
// the hinderance (0 ress surv) is found in the death object

return;
}