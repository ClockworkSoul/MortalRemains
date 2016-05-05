#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A peaceful garden of lilies");
  set("long", wrap(
"The dirt path continues through the lily garden. In this area, the plants "+
"are all pure white, and the foliage is dark and green. It is quiet and "+
"peaceful here, a perfect area for quiet contemplation. A flock "+
"of birds glide silently through the sky above you."
     ) );
  set("item_desc", ([
    "dirt path" : "A narrow dirt path winds through the garden.\n",
    "path" : "A narrow dirt path winds through the garden.\n",
    "plants" : "Pure white flowers bloom throughout the garden.\n",
    "lily garden" : "Pure white flowers bloom throughout the garden.\n",
    "garden" : "Pure white flowers bloom throughout the garden.\n",
    "plant" : "You stop to admire a lovely blossom.\n",
    "lilies" : "Pure white lilies bloom throughout the garden.\n",
    "lily" : "You stop to admire a lovely blossom.\n",
    "foliage" : "The foliage is thick and green.\n",
    "flock" : "A flock of birds glides gracefully above you.\n",
    "birds" : "The birds above you are snow white in color.\n",
    "bird" : "The birds above you are snow white in color.\n",
    "sky" : "A flock of birds glides through the sky above you.\n",
    ]) );
  set("listen", "You listen carefully but hear nothing. It is quiet and "+
      "serene here.\n");
  set("smell", "The scent of the lilies is delicate and sweet.\n");
  set("exits", ([
    "northwest" : P_ROOM+"sunf.c",
    "southwest" : P_ROOM+"lily1.c",
    "northeast" : P_ROOM+"lily3.c",
    ]) );
  set("objects", ([
    "dove": P_MON+"dove.c",
    ]) );
  reset();
  }
