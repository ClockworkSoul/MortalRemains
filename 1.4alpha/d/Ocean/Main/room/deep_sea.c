#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set("underwater" , 1);
    set( "exits", ([
      "up" :  O_ROOM+"sea",
    ]) );

    set("short", "Deep under the sea.");
    set("long" , wrap(
	"You are swimming deep under the sea. Sunlight "+
	"filters down from far above you. It "+
	"dances around through the water making it seem "+
	"like everything is moving. "+
	"All around you is a beautiful multi-"+
	"colored coral reef. Below you is an opening. "+
	"A person sized hole. It seems to call to you. "
      ) );

    //  set("listen", "You can faintly hear the sounds of Whale's singing.\n");
    set("light", 1);
    set("item_desc", ([
      "sea#ocean" : "The water is crystal clear and pleasantly warm. \n",
      "water" : "The water is crystal clear and surrounds your body. \n",
      "fish" : "Small fish are swimming around.\n",
      "small fish" : "Small fish are swimming around.\n",
      "coral" : "A huge coral reef.\n",
      "coral reef#reef" : "It's beautiful and all around you. \n",
      "hole#opening" : wrap("A hole in the coral reef. "+
	"Maybe you could <enter hole>. "),
    ]));
    /*
      set_search_array(({
	    "fish", "The fish squirms out of your hand.\n",
	    "coral", "You cut your hand on the sharp coral!\n",
	    "cave", "You can't search the cave from here.\n"
      }));

    */
}

void init() 
{
    add_action("enter", "enter");
    add_action("smell", "smell");
    add_action("dive", "dive");
    add_action("swim", "swim");
    add_action("search", "search");
}

/*ACTIONS*/

int enter(string arg) {
    if(!arg) {
	notify_fail("enter what?\n");
	return 0;
    }
    if(arg == "hole") {
	say(NAME +" swims down into the hole. \n");
	write("You swim down into the hole. \n\n\n\n\n");
	this_player()->move(O_ROOM+"trans.c");
    }
    if(arg != "hole") {
	write("You can't enter " +  arg +".\n");
    }
    return 1;
}

int smell(string arg) {
    write("You inhale deeply....\nYou convulse in agony as your lungs begin to fill with sea water!\nYou might not want to do that again.\n");
    this_player()->receive_damage((this_player()->query("hit_points") - 1), "poison");
    return 1;
}

int swim(string arg) {
    write("You swim around under the sea.\n");
    return 1;
}

int dive(string arg) {
    /*
    if((int)this_player()->query_level() < 20) {
	    write("You don't want to dive any further at your level.\n");
    } else { if((int)this_player()->query_security_level() <= 19);
	    this_player()->move_player("#/players/gasman/ocean/evil");
    }
    */
    write("You can't dive any deeper.\n");
    return 1;
}

int search(string arg) {
    if(!arg) {
	write("search what?\n");
	return 0;
    }
    if(arg == "coral") {
	write("You cut your hand on the sharp coral!\n");
	this_player()->receive_damage(4,"poison");
    }
    if(arg == "cave") 
	write("You can't search the cave from here.\n");
    if(arg == "fish") 
	write("The fish squirms out of your hand.\n");
    return 1;
}
