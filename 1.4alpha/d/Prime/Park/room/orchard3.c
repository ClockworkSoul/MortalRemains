#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A fruitful orchard");
  set("long", wrap(
"The trees in this section of the orchard are dotted with apples in various "+
"colors. The bright yellow variety looks particularly healthy and ripe. "+
"Fallen apples are scattered about on the ground, and you notice several "+
"apple cores lying near your feet."
     ) );
  set("item_desc", ([
    "trees" : "Ripe apples hang from the trees.\n",
    "apples" : "The apples are ripe and healthy.\n",
    "apple" : "You stop to admore a bright yellow apple.\n",
    "yellow variety" : "The yellow variety seems particularly healthy.\n",
    "fallen apples" : "Fallen apples lie on the ground.\n",
    "apple cores" : "The apples seem to have been eaten by squirrels.\n",
    "apple core" : "This apple seems to have been eaten by a squirrel.\n",
    ]) );
  set("smell", "The air smells faintly of apples.\n");
  set("listen", "You hear birds chirping in the distance.\n");
  set("exits", ([
    "west" : P_ROOM+"elm.c",
    "northwest" : P_ROOM+"orchard2.c",
    "southeast" : P_ROOM+"pool.c",
    ]) );
  set("objects", ([
    "bluejay" : P_MON+"bluejay.c",
    ]) );
  reset();
  }
