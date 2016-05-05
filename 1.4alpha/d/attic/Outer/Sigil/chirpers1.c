#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "harys" : "/d/Outer/Sigil/monsters/harys"]));
  
          set ("light", 1) ;
  set("short", "Chirpers.") ;
  set("long", @ENDLONG
You are in the north room of the second level of Chirpers in the town of 
Sigil.  This area of the pub is remarkably similar to every other area of
the pub- full of tables and chairs, and covered with ale.
ENDLONG
  );
  set("item_desc", ([
   "chairs" : "Plenty of them here.\n",
  "tables" : "1 table per 4 chairs.  Fascinating.\n",
  "ale" : "Mostly dried up.\n",
  ]) ) ;
  set("smell", ([
   "default" : "You smell the ale on the floor, mostly.\n",
  ]) ) ;
     set ("exits", ([
     "south" : SIGIL+"chirpers2.c" ]));
reset();
     }
