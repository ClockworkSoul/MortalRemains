/*
* File: sea.c
* Desc: The first file in the ocean domain
* Originally created by gasman; edited by Herself
*/
#include <mudlib.h>
#include "ocean.h"


inherit ROOM;

int DAMAGED = 0;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set( "light", 1 );
    set("smell" , "It smells like saltwater. \n");
    set("listen" , "You hear the water lapping. \n");
    set("short" , "The Ocean");
    set("long" , wrap(
	"You find yourself far out in the ocean. You can barely make "+
	"out the land behind you. The water below looks crystal clear "+
	"you think you can even see something glittering on "+
	"the bottom of the ocean floor. A large rock is above you. "
      ) );

    set("objects" , ([
      "fish" : O_MON+"fish.c",
      "seahorse" : O_MON+"seahorse.c",
    ]) );
    reset ();
    set( "exits", ([
      "east" : O_ROOM+"sea1.c",
      "west" : O_ROOM+"sea2.c",
      "north" : O_ROOM+"sea13.c",
      "back" :  O_ROOM+"beach",
      "up" : O_ROOM+"rock.c",
    ]) );

    set("item_desc", ([
      "mist" : "It surrounds you. \n",
      "sea" :  "The water is crystal clear and pleasently warm. \n",
      "ocean" :  "The water is crystal clear and pleasently warm. \n",
      "water" :  "The water is crystal clear and pleasently warm. \n",
      "waves" :  "The waves are tossing you all around.\n",
      "sky" :  "The sky is clear except for a few cumulous clouds.\n",
      "clouds" : "The clouds are light and non threatenin g.\n",
      "cumulous clouds" : "The clouds are light and non threatenin g.\n",
      "cloud" : "The clouds are light and non threatenin g.\n",
      "sun" :  "You squint as you look at the sun.\n",
      "bottom" : "You can't see it clearly, maybe if you dive... \n",
      "something" : "Take a closer look, dive! \n",
    ]) );
}
void init()
{
    add_action("drink", "drink");
    add_action("dive_down", "dive");
    add_action("tread", "tread");
    add_action("swim", "swim");
    add_action("float_sea", "float");
}

int dive_down(string arg)
{
if(TP->query_level()<9){
write(@EndText
A few bubble surface beneath you and tell you: You are not yet
ready to venture beneath the surface. Take care and come
back when you have leveled a bit.
EndText);
say(TPN+" starts to dive, but thinks better of it. \n");
return 1;
}
    write("You take a deep breath and dive!\n");
    write(@EndText
  .       .   .    .           O
     .  o .   O       O    .       o
  .    .            O        .
   O        .              o    . O
   .   .        o     .      o
      .   O                 .
  O     .         O
   O        .              o 
    .    O         O
       o .   O        .
	   O     . o
	     O  O
	      .
		o
EndText
    );
    this_player()->move_player(DEEP+"deep_sea.c", "SNEAK", "down");
    return 1;
}

int tread(string arg) 
{
    write("You tread water.\n");
    return 1;
}

int swim(string arg) 
{
    write("You swim around in the ocean.\n");
    return 1;

}

int float_sea(string arg) {
    write("You float on your back.\n");
    return 1;
}


int drink(string arg) 
{
    int HP;
    HP = this_player()->query("hit_points");

    switch(random(34))
    {
    default :
	write("You drink the salt water.\n");
	break;
    case 0 .. 12 :
	write("You drink the sea water.\nIt is salty.\n");
	break;
    case 13 .. 20 :
	write("You are surrounded by a golden glow\n");
	this_player()->receive_healing(random(3), "poison");
	DAMAGED = 1;
	break;
    case 21 .. 28 :
	if(DAMAGED == 1)
	{
	    this_player()->receive_damage((HP - 10), "poison");
	    write ((HP - 10) + "\n");
	    write("You've been poisoned!\n");
	    DAMAGED++; 
	} 
	else 
	{
	    write("You get a mouth full of fowel tasting water.\n");
	    DAMAGED++; 
	}
	break;
    case 29 .. 34 :
	if(this_player()->debit(10))
	{
	    write("While you weren't paying attention, a water demon snatched\n"+
	      "some money out of your purse!\n");
	}
	break;
    }
    return 1;
}
