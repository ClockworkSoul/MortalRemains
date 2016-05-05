#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit MAIN+"/palacestd.c";

int doors_open;

void create()
{
    doors_open = 0;

    ::create();//<- gets all the information from the original create()
    seteuid( getuid() );
    set ("short", "Palace Entrance");
    set( "long", @EndText
Great iron doors dominate the entrance to the Grand Palace. Long
ago, Cyanide had this grand hall built to greet visiting nobles.
Beautiful mural adorns the walls here. A large marble throne rests
at the east end of the chamber. A small door to the east leads to
Cyanide's preparation room.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/phalln1.c",
      "south" : MAIN+"/phalls1.c",
      "east" : MAIN+"/preproom.c",
      "west" : MAIN+"/room6'5.c",
    ]) );
    set ("item_desc", ([
      "floor" : "A large hand, the symbol of Cyanide, "+
      "decorates the floor here.\n",
      "murals" : wrap("They honor the day of the Great Compiling, "+
	"whn "+MUD_NAME+" fist came into existance."),
      "doors" : "@@query_doors",
      "throne" : "It is Cyanide's ancient stone throne.\n",
    ]) );
    set("pre_exit_func", ([
      "west" : "get_out",
    ]) );
}

void init() {
    ::init();
    add_action("open_func", "open");
    add_action("close_func", "close");
}

int get_out() {
    if (doors_open) {
	return 0;
    } else {
	write("The massive doors are closed.\n");
	return 1;
    }
}

string query_doors() {
    if (doors_open) {
	return "The great doors are wide open.\n";
    } else {
	return "The great iron doors are closed and locked.\n";
    }
}

int open_func(string str) {
    if (str=="doors" || str=="door") {
	if (doors_open) {
	    write("The doors are already open!\n");
	    return 1;
	}

	if (TPN=="Cyanide") {
	    write("The doors creak open.\n");
	    say(TPN+" raps his staff against the doors, "+
	      "and they slowly creak open.\n");
	    doors_open = 1;
	} else {
	    write("They won't budge.\n");
	    say(TPN+" tries to open the doors, but nothing happens.\n");
	}
	return 1;
    }
}


/* EOF */
