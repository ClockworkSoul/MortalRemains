#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A reflecting pool");
  set("long", wrap(
"A vast rectangular pool lies before you. It is quite shallow and filled with "+
"clear water. Several ducks swim in the distance, and the clouds overhead are "+
"reflected in the water. It is quiet and still here, one of the park's most "+
"relaxing sites."
     ) );
  set("item_desc", ([
    "rectangular pool" : "The pool is large and shallow.\n",
    "pool" : "The pool is large and shallow.\n",
    "clear water" : "The water is crystal clear.\n",
    "water" : "The water is crystal clear.\n",
    "ducks" : "Ducks swim in the distance.\n",
    "duck" : "A duck swims in the distance.\n",
    "clouds" : "Fluffy white clouds are reflected in the pool.\n",
    ]) );
  set("smell", "You smell flowers from the nearby gardens.\n");
  set("listen", "It is perfectly quiet here.\n");
  set("exits", ([
    "west" : P_ROOM+"path6.c",
    "northwest" : P_ROOM+"orchard3.c",
    "southwest" : P_ROOM+"lily3.c",
    ]) );
    set("objects", ([
      "dove" : P_MON+"dove.c",
    ]) );
  reset();
  }
