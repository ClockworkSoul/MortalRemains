#include <mudlib.h>
#include "sigil.h"

inherit BUYONLY_SHOP ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "wooly" : "/d/Outer/Sigil/monsters/wooly" ]) );
	reset();
     set ("light", 1) ;
   set("short", "Ensin's Elixirs.") ;
    set("shop_dir", SIGIL+"elixers/");
    stock = ([
                   "enlargepotion" : 2 + random(3),
                   "strengthpotion" : random(20),
                    "hastepotion" : 1 + random(2),
                     ]) ;
   set("shopkeeper", "wooly" ) ;
 set("replenish_msg", @ENDMSG
Ensin returns!
He restocks a few vials and goes out to find more!
ENDMSG
  ) ;
     set ("long",
@ENDLONG
You stand in Ensin's Elixir and Speciality Potion shop in Sigil.
The potion tester, Wolly, is looking after the store while
Ensin is away gathering some rare ingredients for new potions.

Commands are: list, buy <item>
please be specific: ex: buy enlargepotion
ENDLONG
  );
  set("exits", ([
        "west" : SIGIL+"newtst2.c"]));
}                                       
