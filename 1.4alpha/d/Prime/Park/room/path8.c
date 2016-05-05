#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a narrow path");
  set("long", wrap(
"The path becomes so narrow here that to move you must trample on the nearby "+
"reeds. The ground near the path is soft, and you sink into it with "+
"every step. A large black bird rest on a branch in the distance, eyeing "+
"you carefully."
     ) );
  set("item_desc", ([
    "path" : "The path is extremely narrow.\n",
    "reeds" : "The reeds are tall and thin.\n",
    "ground" : "The ground is dark and damp.\n",
    "large black bird" : "The bird stares at you intently.\n",
    "black bird" : "The bird stares at you intently.\n",
    "bird" : "The bird stares at you intently.\n",
    "branch" : "A large bird rests atop the branch.\n",
    ]) );
  set("smell", "You smell something rotten nearby.\n");
  set("listen", "You hear the reeds rustling slightly.\n");
  set("exits", ([
    "north" : P_ROOM+"path7.c",
    "south" : P_ROOM+"fountain.c",
    "west" : P_ROOM+"lilac.c",
    "east" : P_ROOM+"picnic.c",
    ]) );
  set("objects", ([
    "dragonfly" : P_MON+"dragonfly.c",
    ]) );
  reset();
  }
