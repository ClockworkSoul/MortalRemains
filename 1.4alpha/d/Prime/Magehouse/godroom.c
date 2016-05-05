#include "newbie.h"
#include <config.h>
#include <mudlib.h>
#include <move.h>

inherit ROOM;

int dh_flag;

void create()
{   
    ::create();
    seteuid( getuid() );

    dh_flag = 1;

    set( "light", 1 );
    set("author","blood");
    set( "short", "Tomb of Wonders" );
    set( "long", @EndText
You are in a chamber of death, the smell of old, dead things accompany
your heavy breathing, and the weight of something else rests on your soul.
A dessicated corpse lies here, in the center of a circle of salt. This
circle you have seen before, it is a circle ward, it is used to prevent
demons and other hellspaun from entering and disturbing its bones. one of
the more interesting things however is the blue light hovering above the
corpse. You haven't seen that before though.    
EndText
    );
    set("item_desc", ([
      "circle" : "It is a standard thaumaturgic circle of protection.\n",
      "salt" : "It is simple, non-magical salt. It has been used to form "+
      "a circle of\nprotection.\n",
      "corpse" : "It is clearly human, but is dressed in clothing from an "+
      "age long since past.\n",
    ]) );
    set( "exits", ([
    ]) );
}   

void init() {
    add_action("search_func", "search");
}

int search_func(string str) {
    if (str=="corpse") {
	object dh;

	dh = clone_object(N_ITEM+"darkheart.c");

	if (!dh) dh_flag = 0;

	if (dh_flag) {    
	    write("On the corpse you find a strange object, and take it.\n");

	    dh->move(TP);
	    dh_flag = 0;
	} else {
	    write("You find nothing.\n");
	    if (dh) destruct(dh);
	}

	say(TPN+" goes through the corpse's pockets.\n");
	return 1;        
    }

    return 0;
}

/* EOF */
