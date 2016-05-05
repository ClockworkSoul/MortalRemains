#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the south room of Chirpers' second floor.  It seems that there
was a fight here recently, because there is quite a mess.  Chairs and 
tables have been overturned, some broken.  The stench of stale beer and
vomit is quite intense here.
ENDLONG
 );
  set("search_desc", ([
   "vomit" :"You'd rather not.\n",
  "floor" : "After much searching, you find nothing but a lot of vomit.\n",
  ]) ) ;
  set("item_desc", ([
   "chairs" : "Many are overturned, some are broken.\n",
  "tables" : "A few are broken, but most remain intact.\n",
  "vomit" : "It's not that interesting.\n",
  "floor" : "You find some vomit on the floor.\n",
  ]) ) ;
  set("smell", ([ "default" : "The stench of vomit and stale beer is quite overpowering.\n" ]) ) ;
 set("short", "Chirpers.") ;
     set ("exits", ([
     "north" : SIGIL+"chirpers2.c" ]));
}
