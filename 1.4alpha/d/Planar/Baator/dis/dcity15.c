#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects" , ([ 	
    "cg1" : BAATOR+"monsters/cornugon",
      "cg2" : BAATOR+"monsters/cornugon"
    ]));
    set ("light", 1) ;
    set ("long", @EndLong
You stand at the gates of the great Iron City of Dis, who's walls glow 
faintly in the darkness, signifying great head. All along the parapets,
hung from chains, are the scorched and charred corpses of the unlucky 
enemies of the Lord Dispater. The plush red road continues to the east.
EndLong
    );
    set ("short","The Iron City of Dis");
    set ("exits", ([
      "east" : BAATOR+"dis/dcity16.c",
      "west" : BAATOR+"dis/dplain9.c"
    ]));
    set("item_desc", ([
    "corpses" : "Some of them are still writhing feebly in pain as they"+
        "burn against the\nwalls of the city.\n",
    "walls" : "They are extraordinarily hot, and glowing a faint red.\n",
    ]) );
    reset();
}
