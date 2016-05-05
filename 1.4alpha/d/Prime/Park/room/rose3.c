#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A fragrant rose garden");
  set("long", wrap(
"Romance is in the air in this section of the garden. Lush red roses are in "+
"full bloom, filling the air with their intoxicating perfume. The path here "+
"is just wide enough for two, and a small statue of Eros aims his bow from "+
"amid the shrubs."
     ) );
  set("item_desc", ([
    "garden" : "This garden is quiet and romantic.\n",
    "red roses" : "The roses are in full bloom.\n",
    "roses" : "The roses are in full bloom.\n",
    "path" : "The path is just wide enough for two.\n",
    "small statue" : "A small statue of Eros hides in the shrubs.\n",
    "statue" : "A small statue of Eros hides in the shrubs.\n",
    "eros" : "Eros aims his bow at passersby.\n",
    "bow" : "Eros aims his bow at passersby.\n",
    "shrubs" : "The shrubs are filled with red roses.\n",
    "shrub" : "This shrub is filled with red roses.\n",
    ]) );
  set("smell", "The air is rich with perfume.\n");
  set("listen", "It is quiet and relaxing here.\n");
  set("exits", ([
    "north" : P_ROOM+"willow.c",
    "southeast" : P_ROOM+"pond2.c",
    "northwest" : P_ROOM+"rose2.c",
    ]) );
  set("objects", ([
    "dove" : P_MON+"dove.c",
    "butterfly" : P_MON+"butterfly.c",
    ]) );
  reset();
  }
