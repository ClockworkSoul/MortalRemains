#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Along a cobblestone path");
  set("long", wrap(
"In this section of the cobblestone path, you are surrounded by large shrubs "+
"dotted with large purple berries. You try to peek over the shrubs, but you "+
"cannot manage to see over them. Fallen purple berries dot the ground "+
"beneath you, staining the brown cobblestones."
     ) );
  set("item_desc", ([
    "cobblestone path" : "The path is surrounded by large shrubs.\n",
    "path" : "The path is paved with cobblestones.\n",
    "large shrubs" : "The shrubs are dark green in color.\n",
    "shrubs" : "The shrubs are dark green in color.\n",
    "large shrub" : "The shrub is dark green in color.\n",
    "shrub" : "The shrub is dark green in color.\n",
    "large purple berries" : "The berries are plump and ripe.\n",
    "purple berries" : "The berries are plump and ripe.\n",
    "berries" : "The berries are plump and ripe.\n",
    "fallen purple berries" : "Fallen berries stain the ground.\n",
    "fallen berries" : "Fallen berries stain the ground.\n",
    "ground" : "The ground is stained by fallen berries.\n",
    "brown cobblestone" : "The brown cobblestone is stained purple in "+
      "places.\n",
    "cobblestone" : "The brown cobblestone is stained purple in places.\n",
    ]) );
  set("smell", "You smell something sweet and fruity.\n");
  set("listen", "You hear rustling in the shrubs.\n");
  set("exits", ([
    "east" : P_ROOM+"fountain.c",
    "west" : P_ROOM+"path2.c",
    "north" : P_ROOM+"lilac.c",
    "south" : P_ROOM+"gazebo.c",
    ]) );
  reset();
  }
