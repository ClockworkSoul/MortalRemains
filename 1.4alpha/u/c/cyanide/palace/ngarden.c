/*
** FILE: A room in /d/Dark/Dark/main/
** PURPOSE: I high-level area with all sorts of surprises.
**    Quite deadly - methinks.
** CHANGES:
**   Mar-10-95  Cyanide@ERock           Created the file.
**   Oct-15-96  Cyanide@AtFoD           Carried in the tradition.
*/

#include <mudlib.h>
#include "main.h"

int f = 4;

inherit MAIN+"/gardenstd.c";

void create()
{
    ::create();
    set ("short", "North End of Garden");
    set( "long", @EndText
This is the northern part of a formal garden. Hedges hide the palace
north. A break in the hedge is almost overgrown to the north. A
carefully manicured path covered with small crushed
white stones leads south. In the center of a rosebed is a small open
structure, painted white. It appears to be a gazebo.
EndText
    );
    set("pre_exit_func", ([
    ]) );
    set( "exits", ([
      "east" : MAIN+"/garden01.c",
      "west" : MAIN+"/garden02.c",
      "south" : MAIN+"/cgarden.c",
      "gazebo" : MAIN+"/gazebo.c",
    ]) );
    set ("item_desc", ([
      "gazebo" : "Well, you can always try entering it.\n",
      "rosebed" : wrap("As you approach, you observe that it is not "+
	"QUITE a bed of roses, but rather some strange, foreign type of flower."),
      "hedges" : "They haven't been trimmed in quite a while.\n",

      "moss" : "It is glowing with a soft yellow-green light.\n",
    ]) );
}

void init() {
    add_action ("pick_func", "pick");   
}


int north() {
    write("A mysterious force bars your way.\n");
    return 1;
}

int pick_func(string str) {
    object roselily;
    if (f>0) {
	if (str!="flowers" && str!="flower") {
	    notify_fail("Pick what?\n");
	    return 0;
	}
	say (TPN+" plucks a single perfect flower from one \n"+
	  "of the flower beds.\n");
	write ("You pluck a delicate flower from one of the beds near the path.\n");
	roselily=clone_object(OBJ+"/flower1.c");
	roselily->move(this_player());
	f--;
	return 1;
    } else {
	write ("There are no good ones left.\n");
	return 1;
    }
}

/* EOF */
