#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
set("long", @ENDLONG
You are the landing to the holding cells of the Gatehouse.
Some stairs lead down here.
ENDLONG
  );
  set("exit_msg", ([
   "down" : "$N descends the stairs.",
 ]) ) ;
  set("short", "Gatehouse.") ;
     set ("exits", ([
     "down" : SIGIL+"gatehouse1.c",
     "east" : SIGIL+"gatehouse4.c",
     "west" : SIGIL+"gatehouse3.c" ]) ) ;
}
