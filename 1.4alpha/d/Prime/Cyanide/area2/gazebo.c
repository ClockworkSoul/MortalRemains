#include <mudlib.h>
#include "main.h"
inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 1);
    set ("short", "Gazebo");
    set( "long", @EndText
This is a gazebo in the midst of a formal garden. It is cool
and restful here. A tea table adorns the center of the gazebo.
EndText
    );
    set( "exits", ([
      "out" : MAIN+"/ngarden.c",
    ]) );
    set ("item_desc", ([
      "table" : "A seeingly useless little table. There is nothing on it.\n",
      "bushes" : "They are clipped into shapes, which you can't make out from
here.\n",
"gazebo":"The inside of the gazebo is calm and relaxing... and you think you\n"+
"can see something peculiar about the seats.\n",
"seat" : "There is some graffiti carved into the seats by an unknown vandal.\n",
"graffiti" : "It reads \"GrUnT WuZ hErE\".\n",
]) );
}
