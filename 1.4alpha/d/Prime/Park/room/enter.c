#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "ellie");
    set("light", 1);
    set("short", "The entrance to Balitor Park");
    set("long", wrap(
	"The entrance to Balitor Park is marked by a magestic stone archway. "+
	"Flowering shrubs are planted on each side of the arch, and a cobblestone "+
	"path leads into the park. As the wind blows gently, you notice the "+
	"faint perfume of flowers in the air."
      ) );
    set("item_desc", ([
      "magestic stone archway" : "The tall archway leads into the park.\n",
      "stone archway" : "The tall archway leads into the park.\n",
      "archway" : "The tall archway leads into the park.\n",
      "arch" : "The tall archway leads into the park.\n",
      "flowering shrubs" : "Bright red flowers dot the large shrubs.\n",
      "flowering shrub" : "Bright red flowers dot the large shrub.\n",
      "shrubs" : "Bright red flowers dot the large shrubs.\n",
      "shrub" : "Bright red flowers dot the large shrub.\n",
      "cobblestone path" : "A cobblestone path leads into the park.\n",
      "path" : "The path is paved with cobblestones.\n",
      "park" : "As you peek in, you notice how green and tranquil the park "+
      "appears.\n",
    ]) );
    set("smell", "As you inhale, you notice the sweet scent of flowers in the "+
      "air.\n");
    set("listen", wrap(
	"You hear the din of the city behind you and look forward to the quiet "+
	"serenity of the park."
      ) );
    set("exits", ([
      "west" : "/d/Prime/Central/room/road0_3.c",
      "east" : P_ROOM+"path1.c",
      "southeast" : P_ROOM+"rose1.c",
      "northeast" : P_ROOM+"veg1.c",
    ]) );
    reset();
}
