#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {
    ::create();
    set("short", "At the Gates of Jangling Hiter");
    set("long", @EndText
You are standing just outside the gates of a large town, its walls forged
out of thousands of massive links of chain, each one as large as a fully
grown human. To the east continues a vast bog, around which the stench of
rot and decay settles as a green haze.
EndText
    );
    set("item_desc", ([
      "gates" : "They are huge, and also made from welded steel chains.\n",
      "chains" : "It seems the whole city os made from them.\n",
      "links" : "You can't imagine how these were brought here.\n",
      "stench" : "It's so thick, you can see the green haze over the bog.\n",
      "bog" : "It's so thick, you can only make out its edge.\n",
    ]) );
    set("smell", ([
      "stench" : "The stench is so foul you nearly faint.\n",
      "bog" : "You can't seem to help smelling the bog.\n",
      "default" : "You barely manage to keep from gagging.\n"
    ]) );
    set ("exits", ([   
      "east" : BAATOR+"minauros/bog12.c",  
      "west" : BAATOR+"minauros/hiter15.c"
    ]));
    reset();
}
