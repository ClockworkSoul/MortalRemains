#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a quiet path");
  set("long", wrap(
"Sunny daffodils are planted on either side of the red brick path in this "+
"area. You watch them for a moment, as they sway gracefully in the gentle "+
"breeze. You hear a bee buzzing softly as it flits from flower to flower."
     ) );
  set("item_desc", ([
    "sunny daffodils" : "The daffodils are bright and cheerful.\n",
    "daffodils" : "The daffodils are bright and cheerful.\n",
    "daffodil" : "You stop to examine a delicate daffodil.\n",
    "flower" : "The daffodil is sunny and cheerful.\n",
    "flower" : "The flowers are sunny and cheerful.\n",
    "red brick path" : "The path is paved with red bricks.\n",
    "brick path" : "The brick path is quite narrow.\n",
    "path" : "The brick path is quite narrow.\n",
    "bee" : "A yellow and black bee flits from flower to flower.\n",
    ]) );
  set("smell", "You smell the fresh scent of the daffodils.\n");
  set("listen", "You hear only the buzzing of a bee.\n");
  set("exits", ([
    "east" : P_ROOM+"path6.c",
    "west" : P_ROOM+"path4.c",
    "north" : P_ROOM+"field2.c",
    "south" : P_ROOM+"statue2.c",
    ]) );
  reset();
  }
