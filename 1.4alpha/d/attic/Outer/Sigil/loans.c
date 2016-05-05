#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Dernon's Loan Office.") ;
  set("long", @ENDLONG
The building you are in is still under heavy construction.  Pieces of
wood and various tools lie scattered about the room carelessly.  It appears
that the construction workers are absent, however.

A large sign hangs on the wall here.
ENDLONG
  ) ;
  set("item_desc", ([
   "wood" : "Just pieces of wood being used to build this place.\n",
   "tools" : "Nothing of any use.\n",
   "sign" : "You could read it.\n",
  ]) ) ;
     set ("exits", ([
	"east" : SIGIL+"turtlest1.c"]));
}


void init() {
  add_action("read", "read") ;
}

int read(string str) {
  if (!str) {
    write("Read what?\n");
    return 1;
  }
  if (str == "sign") {
  write(@ENDSIGN
The sign reads:

	The Interest Rate on all loans is currently at 100%.

	The loan shop is currently not open.  Please come back later.
ENDSIGN
  );
  say(TPN+" reads the sign.\n") ;
  return 1;
  } else return 0;
}
