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
"Large pink roses dot dark green shrubs in this small garden. The path winds "+
"among the shrubs, and petals from the flowers lie scattered about the "+
"ground beneath you. You hear the buzzing of bees nearby and occassionally "+
"spot one by a flower."
     ) );
  set("item_desc", ([
    "pink roses" : "The roses are a delicate shade of pink.\n",
    "pink rose" : "This rose is large and fragrant.\n",
    "roses" : "The roses are a delicate shade of pink.\n",
    "rose" : "This rose is large and fragrant.\n",
    "green shrubs" : "The shrubs are deep, dark green.\n",
    "green shrub" : "This shrub is deep, dark green.\n",
    "shrubs" : "The shrubs are deep, dark green.\n",
    "shrub" : "This shrub is deep, dark green.\n",
    "small garden" : "This garden is small and intimate.\n",
    "garden" : "This garden is small and intimate.\n",
    "path" : "A stone path winds through the shrubs.\n",
    "petals" : "Petals are scattered about on the ground.\n",
    "ground" : "Petals are scatterd about on the ground.\n",
    "bees" : "Buzzing bees flit about near the flowers.\n",
    "flowers" : "The flowers are large and fragrant.\n",
    "bee" : "This buzzing bee flits about near a flower.\n",
    "flower" : "This flower is large and fragrant.\n",
    ]) );
  set("listen", "You hear the buzzing of bees.\n");
  set("smell", "The scent of the roses is strong and sweet.\n");
  set("exits", ([
    "east" : P_ROOM+"dogwood.c",
    "northwest" : P_ROOM+"enter.c",
    "southeast" : P_ROOM+"rose2.c",
    ]) );
  set("objects", ([
    "bee" : P_MON+"bee.c",
    "robin" : P_MON+"robin.c",
    ]) );
  reset();
  }
