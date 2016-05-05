#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
  set("author","cattt");
  set("light", 1);
  set("short", "Backway into the sewer");
  set("long", wrap(
   "The walls just drip sewage.  The smell of this area is nausiating. "
      ) );
  set("item_desc", ([
   "walls":"Dark and dreary but also wet with sewage.\n",
   "sewage":"You really don't want to know what this is.\n",
                  ]) );
  set("smell", ([
   "default": "The smell of shit and garbage smothers you.\n",
                  ]) );
  set("exits", ([
     "door" : M_ROOM+"basement2.c",
    ]) );
}
