#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "In a spacious gazebo");
  set("long", wrap(
"You have entered a gazebo, painted bright white with ornate dark blue "+
"trim. The floor is covered with shiny wooden planks, and simple benchs "+
"lie along the edges. Potted plants with cheerful flowers are placed "+
"throughout and ferns hang from the rafters above your head."
     ) );
  set("item_desc", ([
    "gazebo" : "The gazebo is quite large.\n",
    "ornate trim" : "The trim is painted dark blue.\n",
    "trim" : "The trim is painted dark blue.\n",
    "dark blue trim" : "The dark blue trim is quite ornate.\n",
    "blue trim" : "The dark blue trim is quite ornate.\n",
    "shiny wooden planks" : "The planks have been polished to a high shine.\n",
    "planks" : "The planks have been polished to a high shine.\n",
    "shiny planks" : "The planks are made of wood.\n",
    "wooden planks" : "The planks have been polished to a high shine.\n",
    "plank" : "The plank is made of wood.\n",
    "floor" : "The floor is covered with wooden planks.\n",
    "simple benches" : "The benches are simple but comfortable.\n",
    "benches" : "The benches are simple but comfortable.\n",
    "bench" : "The bench is simple but comfortable.\n",
    "simple bench" : "The bench is simple but comfortable.\n",
    "edges" : "Simple benches line the edges of the gazebo.\n",
    "edge" : "Simple benches lie along the edge of the gazebo.\n",
    "potted plants" : "Terracotta pots hold flowering plants.\n",
    "plants" : "Terracotta pots hold flowering plants.\n",
    "potted plant" : "The plant is in a terracotta pot.\n",
    "plant" : "The plant is in a terracotta pot.\n",
    "cheerful flowers" : "Colorful flowers bloom on the plants.\n",
    "flowers" : "The flowers are bright and cheerful.\n",
    "cheerful flower" : "The flower is bright and cheerful.\n",
    "flower" : "The flower is bright and cheerful.\n",
    "fern" : "A large fern hangs above your head.\n",
    "ferns" : "Large ferns hang above your head.\n",
    "rafters" : "Wooden rafters form the ceiling above you.\n",
    "rafter" : "The rafter is made of wood.\n",
    ]) );
  set("smell", "You smell the nearby flowers.\n");
  set("listen", "You hear birds chirping in the distance.\n");
  set("exits", ([
    "north" : P_ROOM+"path3.c",
    "east" : P_ROOM+"path9.c",
    "southwest" : P_ROOM+"rose2.c",
    ]) );
  set("objects", ([
    "butterfly" : P_MON+"butterfly.c",
   ]) );
  reset();
  }
