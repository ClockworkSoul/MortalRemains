#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("long", @EndText
You are on a huge sandy battle plain, stained a dark red from millenia of
ruthless carnage and bloodshed. The ground becomes rockier to the south, 
where a narrow path leads up into the mountains.
EndText
    );
    set ("exits", ([
      "west" : BAATOR+"avernus/plain19.c",
      "south" : BAATOR+"avernus/ave3.c",
      "north" : BAATOR+"avernus/plain16.c"
    ]));
}
