#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short","The Verdigris Plains of Dis");
    set ("long", @EndText
You are standing on a vast landscape of rolling, lifeless hills. The 
ground here is the sickly green color of oxidized copper, and the sky
above is a solid ash-green, without features. A few hundred feet to the
east, a massive city with faintly glowing, smoking walls can be seen. 
Starting here and leading toward the city gates is a plush red carpeted
road, sharply contracting with the dead, green soil.
EndText
    );
    set ("exits", ([
        "east" : BAATOR+"dis/dcity15.c",
        "north" : BAATOR+"dis/dplain8.c",
        "south" : BAATOR+"dis/dplain10.c",
        "west" : BAATOR+"dis/dplain4.c"
    ]));
    set("item_desc", ([
    "hills" : "They are rocky and lifeless.\n",
    "ground" : "It seems to be made of kind of hard green substance.\n",
    "sky" : "It is completely still and featureless, without a sun or clouds.\n",
    "city" : "From here, you can feel the heat radiating form the city.\n",
    "road" : "It is immaculately clean, and leads toward the city to the east.\n",
    ]) );
}
