#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndText
You are on a narrow rocky path, winding its way up into the mountains. The
footing here is treacherous at best, and you stumble more than once in you
climb up. To the north, you can reach the Plains of Blood, and the way
west leads higher up into the mountains.
EndText
);
   set("short", "A Rocky Mountain Path.") ;
    set ("exits", ([
      "north" : BAATOR+"avernus/ave3.c",
      "west" : BAATOR+"avernus/ave5.c"
,
   "south" : BAATOR+"avernus/ave7",
    ]));
}
