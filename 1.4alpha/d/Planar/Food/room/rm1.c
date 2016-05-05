#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../food.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "The Village of Foodsburg");
    set( "long", @EndText
You are about to enter a very strange village indeed. You can see 
that the inhabitants seem to be food. You see all sorts of odd stuff
walking around, mabye you better go and investigate.
There is a strange brown-grey portal here.
EndText
    );
    set( "exits", ([
      "north" : RM+"rm2.c",
    ]) );
    set("item_desc", ([
      "portal" : "You could probably 'enter' it, if you chose.\n",
      "village" : "A village of food, how odd.\n",
      "floor" : "Right there under you feet, what did you expect?\n",
    ]) );
}

void init() {
    add_action("enter", "enter");
}

int enter (string str) {
    if (str && str=="portal") {
	write("You crawl into the tiny portal...\n");
	say(TPN+" squeezes into the tiny portal.\n");

	TP->move_player("/d/Prime/Central/room/junkyard01.c", "SNEAK");
	return 1;
    }

    write("Enter what?\n");
    return 1;
}

