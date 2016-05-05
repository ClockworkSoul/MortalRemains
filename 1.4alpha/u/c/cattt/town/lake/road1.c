
#include "town.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "cattt");
    set("light", 1);
    set("short","A road along the waters edge");
      set("long", @EndText
The road looks well travled here.  Sand and dirt line the road
while rocks define the edges.  Looking across the gleaming lake
takes a strong eye as it is quite large.  Small plants and shrubs
grow by the road helping to develop its path.    
EndText
    );
    set("exits", ([
      "northwest" : M_LAKE+"forest1.c",
     "northeast" : M_LAKE+"path1.c",
     "south" : M_PLAINS+"path1.c",
    ]) );
    set("item_desc", ([
      "lake" : "The lake is quite large and very beautiful.\n",
      "water" : "Wind gently blows the water toward the shore.\n",
      "forest" : "The large trees make it hard to see into the forest.\n",
 "breeze" :"The breeze is warm to your skin.\n",
 "building":"The building is too far to make out its use.\n",
 "boats":"The boats look small from here.\n",
 "path":"A well beaten path leading into the forest.\n",
 "hill":"The hill is covered in greenery but that's all you notice from here.\n",
 "reflection":"The hill's reflection shimmers along the water.\n",
"bird":"A small bird can be heard chirping, but not seen.\n",
"treetop":"There are so many it is too hard find just one.\n",
"edge":"Small pebbles and grass line the edge of the lake.\n",
    ]) );
    set("smell", ([
    "default" : wrap("Clean crisp air fills your lungs."),
    ]) );
    //set("objects", ([
      //"human" : M_MON+"dockworker.c",
    //]) );
    reset();
}

void init() {
    add_action("read_func", "read");
}

int read_func(string str) {
    if (str && str=="sign")
	write("The sign reads: Pier 1.\n");
    else
	write("Read what?\n");

    return 1;
}



/* EOF */
