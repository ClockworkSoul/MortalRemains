#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A playing field");
  set("long", wrap(
"A playing field stretches out before you. Quite large, it is covered in "+
"soft grass and bordered by a hedge of shrubs. Thin white lines mark the "+
"edges, but they appear to be faded at the moment. You notice a large "+
"bird circling overhead and begin to get a bit nervous by its attention.",
     ) );
  set("item_desc", ([
    "playing field" : "The playing field is quite large.\n",
    "field" : "The playing field is quite large.\n",
    "soft grass" : "The grass is bright green in color.\n",
    "grass" : "The grass is bright green in color.\n",
    "hedge" : "Shrubs form a hedge around the edge of the field.\n",
    "shrubs" : "The dark green shrubs are quite short.\n",
    "shrub" : "The dark green shrub is quite short.\n",
    "edge" : "A white line marks the edge of the field.\n", 
    "edges" : "White lines mark the edges of the field.\n",
    "large bird" : "The bird above is large and black. You shudder as "+
      "you look up at it.\n",
    "bird" : "The bird above is large and black. You shudder as you look up "+
      "at it.\n",
    "lines" : "White lines mark the edge of the field.\n",
    "line" : "The line appears faded.\n",
    "thin white lines" : "White lines mark the edge of the field.\n",
    "thin white line" : "The line appears faded.\n",
    "white lines" : "White lines mark the edge of the field.\n",
    "white line" : "The white line appears faded.\n",
    ]) );
  set("smell", "You smell the fresh scent of cut grass.\n");
  set("listen", "The bird overhead squawks loudly at you.\n");
  set("exits", ([
    "north" : P_ROOM+"path2.c",
    ]) );
  reset();
  }
