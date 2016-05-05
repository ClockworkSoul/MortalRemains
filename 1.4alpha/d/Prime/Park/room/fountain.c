#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Before a magnificent fountain");
  set("long", wrap(
"Before you stands a fountain of breath-taking beauty. Water sprays high "+
"into the sky, and you feel a mist gently hitting your face. Ornate "+
"carvings cover the fountain, and you notice a particularly lovely carving "+
"of a dancing nymph. A shallow pool surrounds the fountain, filled with "+
"crystal clear water."
     ) );
  set("item_desc", ([
    "fountain" : "The fountain is breath-taking in its beauty.\n",
    "water" : "Water sprays high into the sky.\n",
    "sky" : "Water sprays high into the sky.\n",
    "mist" : "A fine mist is in the air.\n",
    "ornate carvings" : "The fountain is covered in lovely carvings.\n",
    "carvings" : "The fountain is covered in lovely carvings.\n",
    "lovely carving" : "A particularly lovely carving depicts a dancing "+
      "nymph.\n",
    "carving" : "A particularly lovely carving depicts a dancing nymph.\n",
    "dancing nymph" : "The carving depicts a happy nymph dancing in a "+
      "garden.\n",
    "nymph" : "The carving depicts a happy nymph dancing in a garden.\n",
    "shallow pool" : "Clear water shimmers in the pool.\n",
    "pool" : "Clear water shimmers in the pool.\n",
    "crystal clear water" : "You peer into the water and see your reflection "+
      "staring back at you.\n",
    "clear water" : "You peer into the water and see your reflection "+
      "staring back at you.\n",
    ]) );
  set("smell", "The scent of flowers drifts in from the surrounding "+
        "gardens.\n");
  set("listen", "You hear only the splashing water of the fountain.\n");
  set("exits", ([
    "east" : P_ROOM+"path4.c",
    "west" : P_ROOM+"path3.c",
    "north" : P_ROOM+"path8.c",
    "south" : P_ROOM+"path9.c",
    ]) );
  set("objects", ([
    "pigeon" : P_MON+"pigeon.c",
    ]) );
  reset();
  }
