/*
** Creator: Cyanide (28 Jan 98)
*/

#include <mudlib.h>
#include "../cy.h"

void clean_up_pack();
void make_alpha(object);

inherit ROOM;

object alpha = 0, *pack = ({});

void create() {
    ::create();
    set("light", 1);
    set("author", "cyanide");
    set("long", wrap("You are standing on a rocky, uneven path on "+
	"the side of a mountain. Vegetation grows alongside the path, "+
	"stunted by the salt-filled air and apparent lack of sunlight. "+
	"There is a treacherous climb up leading to the top of the "+
	"cliff, and the path continues to the north.") );
    set("short", "An Uneven Mountain Path");
    set("exits", ([
      "up" : AREA1("a1climb01.c"),
      "south" : AREA1("a1path03.c"),
      "north" : AREA1("a1path05.c"),
    ]) );
    set("item_desc", ([
      "cliff" : "It is very high up, and a vast ocean lay at its bottom.\n",
      "ocean" : wrap("Its waters are very rough, and waves crash "+
	"against the cliff bottom."),
      "sky" : "It seems that a storm is brewing.\n",
      "vegetation" : "It consists mainly of hearty grasses.\n",
      "grasses" : "It's just grass.\n",
      "rocks" : "Just rocks.\n",
      "dirt" : "It is everywhere.\n",
      "ground" : "It is under you, as it should be.\n",
      "path" : "It runs from the south to the north here.\n",
      "sunlight" : "The sun is hidden behind thick cloud cover.\n",
      "climb" : "It appears to have been carved out by erosion.\n",
    ]) );	
    set("search_desc", ([
      "sky" : "How the hell are you going to manage that?!\n",
      "vegetation" : "Just hearty, knotted grasses.\n",
      "climb" : "You discover that you can go up from here! (duh)\n",
      "default" : "This strikes you as pointless.\n",
    ]) );
    set("smell", ([
      "air" : "Very salty from the ocean waters at the bottom "+
      "of the cliff.\n",
      "default": wrap("The air is very salty from the ocean waters at the "+
	"bottom of the cliff."),
    ]) );
    set("listen", ([
      "default" : "You hear a constant roaring in the distance to "+
      "the northeast.\n",
    ]) );
}

void reset() {
    int i;
    object ob;

    ::reset();
    /*

	seteuid(getuid());

	clean_up_pack();

	i = random(4) + 2;

	while (sizeof(pack) <= i) {
	    ob = clone_object("/d/Prime/Cyanide/monsters/displacer"); 
	    if (ob) {
		ob->move(TO);
		if (!alpha) make_alpha(ob);
		pack += ({ ob });
	    } else {
		ob = find_player("cyanide");
		if (ob) tell_object(ob, "No ob!\n");
		i = -1;
	    }
	}
    */
}


// This func pulls out any dead beasts from the "pack"

void clean_up_pack() {
    int i;
    object *tmp = ({});

    for (i=0; i<sizeof(pack); i++)
	if (pack[i]) tmp += ({ pack[i] });

    pack = tmp;

    if (alpha)
	for (i=0; i<sizeof(pack); i++) 
	{
	    if (pack[i]!=alpha) pack[i]->set("following", alpha);
	    pack[i]->set("speed", 2);
	}
    return;
}


// This function assigns an alpha beast.
void make_alpha(object ob) {
    int hp, lvl;

    if (!ob) { 
	clean_up_pack();
	if (sizeof(pack) < 2) {
	    alpha = pack[random(sizeof(pack))];
	} else {
	    alpha = 0;
	    reset();
	}
    } else {
	alpha = ob;
	clean_up_pack();
	hp = (int)alpha->query("max_hp") - 
	(int)alpha->query("hit_points");

	lvl = alpha->query_level();  // Just in case.
	alpha->set_level(lvl + 2);   // We make it mack.

	// set_level() reset it's hp's. Here we fix that.
	alpha->add("hit_points", hp * -1);
    }

    ob->set("moving", 1);
    return;
}

/* EOF */
