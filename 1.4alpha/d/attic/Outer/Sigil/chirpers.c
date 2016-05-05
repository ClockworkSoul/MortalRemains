#include <mudlib.h>
#include "sigil.h"

inherit PUB;

void create() {
     ::create();
	seteuid(getuid());
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand in the midst of drunken, sloppy merriment and general raucous
in yet another great pub in Sigil - Chirpers.  A burly man with heavyset
features tends the bar, and tends it well.

A rickety staircase leads up into the second level of the pub.

Commands are: menu, buy <drink>, powerheal <drink>
ENDLONG
  );
    set("short", "Chirpers.") ;
  set("smell", ([
  "default" : "The smell of stale beer and vomit fills the room.\n",
]) ) ;
  set("exit_msg", ([
   "up" : "$N heads up the stairs to the second level.\n",
   "west" : "$N heads out into the street.\n",
  ]) ) ;
  set("item_desc", ([
   "man" : "He's the bartender.  He looks like he's experienced.\n",
   "bar" : "It's got all your alcohol needs.\n",
  ]) ) ;
     set ("exits", ([
     "up" : SIGIL+"chirpers2.c",
"west" : SIGIL+"duskgatest1.c" ]));
// let's make sure that lazy ass barmaid is working.
//   :)
  find_object_or_load("/d/Outer/Sigil/chirpers3") ;
}

