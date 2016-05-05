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
    set("objects" , ([
      "lev" : O_MON+"leviathan.c",
    ]) );
    reset();
    set( "exits", ([
      "south" : DEEP+"deep16.c",
    ]) );

    set("short" , "Leviathan's Lair");
    set("long" , wrap(
	"This is the huge home of the beast Leviathan. "+
	"The entire room seems to be carved out of stone. "+
	"Remains of unlucky passersby scatter the floor. "
      ) );

    set("light", 1);
    set("item_desc", ([
      "room" : "Leviathan's lair. \n",
      "stone" : "Grey stone, carved into a cave where Leviathan lives. \n",
      "remains" : "Bones and stuff. EW! \n",
      "floor" : "A stone floor. \n",
    ]));
}

void init() 
{
    add_action("smell", "smell");
    add_action("swim", "swim");
}

/*ACTIONS*/

int smell(string arg) {
    write("You inhale deeply....\nYou convulse in agony as your lungs begin to fill with sea water!\nYou might not want to do that again.\n");
    this_player()->receive_damage((this_player()->query("hit_points") - 1), "poison");
    return 1;
}

int swim(string arg) {
    write("You swim around under the sea.\n");
    return 1;
}

