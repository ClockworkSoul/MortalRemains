#include "main.h"

inherit MAIN+"/gardenstd.c";

void create()
{
    ::create();
    set("short", "A Beautiful Garden");
    set( "long", @EndText
Trees fruited with many intoxications overhang your path, and 
flowers bow obsequiously as you pass. An inch above the ground, dull as
agates, the eyes of mandrakes follow your tread. The humidity here
strikes you suddenly, and you begin to perspire slightly.
EndText
    );
    set("item_desc", ([
      "path" : "It is covered by small white stones.\n",
      "stones" : "They're just stones.\n",
      "trees" : "You get light-headed as you look at them.\n",
      "flowers" : "They bow to the ground as you walk near.\n",
      "mandrakes" : wrap("The are flowers with what "+
	"appears to be a set of whiteless eyes."), 
    ]) );
    set( "exits", ([
      "east" : MAIN+"/ngarden.c",
      "south" : MAIN+"/gpathw.c",
    ]) );
}
