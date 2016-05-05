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
"Tall shrubs flank the path here, blocking out your view of the "+
"surrounding gardens. The path is quite narrow here and paved with "+
"red brick. You hear chirping emanating from the shrubs, and occassionally "+
"a small bird passes overhead."
     ) );
  set("item_desc", ([
    "tall shrubs" : "The shrubs are taller than you are!\n",
    "shrubs" : "The shrubs are taller than you are!\n",
    "path" : "The path is paved with red brick.\n",
    "red brick" : "The path is paved with red brick.\n",
    "brick" : "The path is paved with red brick.\n",
    "small bird" : "A small bird flies overhead.\n",
    "bird" : "A small bird flies overhead.\n",
    ]) );
  set("smell", "You detect the faint scent of flowers from the surrounding "+
      "gardens.\n");
  set("listen", "You hear chirping from the bushes nearby.\n");
  set("exits", ([
    "east" : P_ROOM+"path5.c",
    "west" : P_ROOM+"fountain.c",
    "north" : P_ROOM+"picnic.c",
    "south" : P_ROOM+"sunf.c",
    ]) );
  set("objects", ([
    "sparrow" : P_MON+"sparrow.c",
    "bluejay" : P_MON+"bluejay.c",
    ]) );
  reset();
  }
