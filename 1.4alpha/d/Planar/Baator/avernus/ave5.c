#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    set ("light", 1) ;
    set ("long", @EndText
You are in a large rocky clearing at the terminus of the path. A few hardy
black weeds grow in ugly tangles between the jagged boulders. To the west
is the entrance to a very large cavern.
EndText
);
    set ("short","Before a Great Cavern");
    set ("exits", ([
      "east" : BAATOR+"avernus/ave4.c",
      "west" : BAATOR+"avernus/ave6.c"
    ]));
    set("item_desc", ([
    "cavern" : "It is rather dark, and is quite large.\n",
    "cave" : "It is rather dark, and is quite large.\n",
    "tangles" : "They are bizarre and unnatural tangles of thorny vines. "+
        "They seem to\ntremble with anticipation as you draw near.\n",
    "weeds" : "They are bizarre and unnatural tangles of thorny vines. "+
        "They seem to\ntremble with anticipation as you draw near.\n",
    "boulders" : "They are some kind of red stone, and have very "+
        "sharp, rough edges.",    
    ]) );
}
