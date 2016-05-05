/*
** FILE: A room in /d/Prime/Cyanide/area2
** PURPOSE: I high-level area with all sorts of surprises.
**    Quite deadly - methinks.
** CHANGES:
**   Mar-10-95  Cyanide@ERock           Created the file.
**   Oct-15-96  Cyanide@AtFoD           Carried in the tradition.
**   Jan-05-00  Cyanide@MR              Moved this room into my palace.
*/

#include <mudlib.h>

#include "main.h"

inherit MAIN+"/gardenstd.c";

object rocks;

int f = 5;
int i = 3;

void create()
{
    ::create();
    f = 5;
    i = 3;
    set ("short", "Formal Garden");
    set( "long", @EndText
This is the middle part of a formal garden. The path is of small 
crushed white stones. It winds among bushes and flower beds in all 
four cardinal directions. To the north a small structure can be  
seen. To the south are peculiarly shaped bushes.
EndText
    );
    set( "exits", ([
      "south" : MAIN+"/topiary.c",
      "east" : MAIN+"/gpathe.c",
      "west" : MAIN+"/gpathw.c",
      "north" : MAIN+"/ngarden.c",
    ]) );
    set ("item_desc", ([
      "hedges" : "They're rather overgrown, but were once quite ornate.\n",
      "stones" : "They are small, crushed white stones, not native to this region.\n",
      "path" : "It is made up of thousands of crushed white stones. It winds around\n"+
      "leading from north to south.\n",
      "structure" : "It seems to be a gazebo of sorts.\n",
      "moss" : "It is glowing with a soft yellow-green light.\n",
      "flowers" : "They are both foreign and beautiful. Perhaps you"+ 
      "could pick\none?\n",
      "beds" : "They are both foreign and beautiful. Perhaps you"+
      "could pick\none?\n",
      "flower beds" : "They are both foreign and beautiful. Perhaps you"+
      "could pick\none?\n",
    ]) );
}

void init() {
    add_action ("rock_func", "take");
    add_action ("rock_func", "get");
    add_action ("pick_func", "pick");
    add_action ("rock_func", "search");
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

int rock_func(string str) {
    if (i>0) {
	if (str!="path" && str!="rocks" && str!="stones" 
	  && str!= "rock" && str!="stone") {
	    return 0; }
	rocks=clone_object(OBJ+"/stone1.c");
	rocks->move(this_player());
	say (NAME+" picks up a small white stone from the path.\n");
	write ("You find a small, sharp rock, and pick it up.\n");
	i--;
	return 1;
    } else {
	write ("There are no good ones left.\n");
	return 1;
    }
}
