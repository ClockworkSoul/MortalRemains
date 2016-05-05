#include "main.h"
#include <config.h>
#include <teleport.h>
#include <move.h>
#include <mudlib.h>

inherit ROOM;

int dagger = 1;

void create()
{
    ::create();
    seteuid( getuid());
    set("short", "Temple");
    set("no_teleport", NO_IN_OR_OUT);
    set( "long", wrap("This large temple was once a temple "+
	"to the ancient and forgotten gods of the previous "+
	"inhabitants of "+CITY_NAME+", but was claimed by "+
	LORD_NAME+" when he took control of the city. The "+
	"doors are guarded by dragon statues similar to those "+
	"found outside. Like the left-side statue at the doors "+
	"of the city, the left-side statue here has also been "+
	"shattered. The walls and ceiling are also heavily "+
	"damaged.Only a humble stone font has escaped damage.\n"+
	"There are dozens of charred corpses littering the floor here.") );
    set( "exits", ([
      "north" : MAIN+"/room4'5.c",
    ]) );
    set("listen", wrap("You hear what sounds like a chorus "+
	"of groaning voices, far away."));
    set("smell", wrap("The stench of charred wood, dust, and "+
	"rotting corpses assaults you."));
    set ("item_desc", ([
      "corpses" : "There are nothing but black, charred bones.\n",
      "statue" : "It has been shattered by a mighty blow.\n",
      "walls" : "They seem to be sturdy, even still.\n",
      "ceiling" : wrap("It has taken a great deal of explosive "+
	"fire damage from an unknown source. It may collapse at "+
	"any moment."),
      "statues" : "Black dragons composed of some glasslike substance.\n",
      "font" : wrap("It is a humble silver bowl on a stand. It still "+
	"contains some very clear water.\n"),
      "water" : wrap("Its holy properties most likely allowed "+
	"it to resist stagnation."),
    ]) );
    set("search_desc", ([
      "font" : "You observe that the silver isn't even tarnished.\n",
      "water" : "@@query_water",
    ]) );
    set("search_func", ([
      "shape" : "shape",
    ]) );

}

string query_water() {
    string str = "";

    if (dagger)
	str = "There appears to be a shape in the water.\n";

    return str;
}


int shape() {
    string str;
    object ob;

    if (dagger) {
	ob = clone_object(OBJ+"/glassdagger.c");
	if (!ob || ob->move(TP) != MOVE_OK) {
	    if (!ob || ob->move(TO)!=MOVE_OK) {
		write("Error: Notify Cyanide!\n");
		return 1;
	    }
	}
	write("It appears to be a glass dagger, nearly invisible in the water!\n");
    } else
	write("You find nothing significant.\n");

    return 1;	
}

/* EOF */
