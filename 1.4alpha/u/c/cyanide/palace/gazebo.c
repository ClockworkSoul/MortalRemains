#include <mudlib.h>
#include "main.h"

inherit MAIN+"/palacestd.c";

void create()
{
    ::create();
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
      "bushes" : wrap("They are clipped into shapes, which you can't make "+
	"out from here."),
      "gazebo":"The inside of the gazebo is calm and relaxing... and you think you\n"+
      "can see something peculiar about the seats.\n",
      "seat" : "There is some graffiti carved into the seats by an unknown vandal.\n",
      "graffiti" : "It reads \"GrUnT WuZ hErE\".\n",
    ]) );
}
