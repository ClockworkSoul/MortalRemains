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
    set ("short", "Bone piles");
    set( "long", @EndText
As Lim-Dul and his servants pillaged the city, this location
became the garbage piles where anything in their way was tossed.
Literally dozens of ancient corpses lie in huge piles.
EndText
    );
    set("arena", 1);
    set( "exits", ([
      "north" : MAIN+"/room5'7.c",
      "south" : MAIN+"/room5'5.c",
    ]) );
    set ("item_desc", ([
      "piles" : "They are huge piles of bones, still covered with the remains\n"+
      "of rotted flesh.\n",
      "bones" : "They are primarily dwarven, and quite old.\n",
      "corpses" : "Well, old bones, really.\n",
    ]) );
}
