#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();//<- gets all the information from the original create()
    seteuid( getuid());
    set( "light", 1 );
    set("area_type", ([
      "black" : 2,
    ]) );
    set ("short", "Avenue of the Hanged");
    set( "long", @EndText
Groaning voices fill the air as you enter this section of the Dead City.
The signs of battle are evident beside the wonders of the place. Soft
light glows from the ceiling, illuminating the burnt and shattered
remains of buildings. Ancient corpses little the floor. As you wander
through the city, you discover an evil sight: from great and
seemingly unlikely trees lining the road, hundreds of corpses hang,
each one with an evil light in its eyes, and groaning in the
eternal pain of undeath.
EndText
    );
    set("arena", 1);
    set( "exits", ([
      "east" : MAIN+"/room6'5.c",
      "west" : MAIN+"/room4'5.c",
      "north" : MAIN+"/room5'6.c",
    ]) );
    set("item_desc", ([
      "trees" : "They are long since dead and decayed. They seem to show signs of\n"+
          "ancient fire damage. From the branched of each tree hangs at
least\n"+
          "three ancient dwarven corpses, all moaning piteously.\n",
"corpses":"They are hanging limplly from broken necks; their dried skin
pulled\n"+
          "tight against their old bones. Their moans resonate about the
city.\n",
  ]) );
}
