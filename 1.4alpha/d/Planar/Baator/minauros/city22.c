#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects", ([ "minauros" : BAATOR+"monsters/minauros" ]));
    set ("light", 1) ;
    set ("long", @EndLong
You have entered the throne room of the terrible Minauros himself. His throne,
also made of dark black stone, is actually more of a pool; it is large and
round, and filled with several feet of fetid, smelly black water.
EndLong
    );
    set ("short","Throne Room of Minauros");
    set("item_desc", ([
      "pool" : "Minauros' version of a throne.\n",
      "water" : "It is smelly and disgusting.\n",
    ]) );
    set ("exits", ([   
      "south" : BAATOR+"minauros/city29.c",
      "west" : BAATOR+"minauros/city21.c"
    ]));
    reset();
}


