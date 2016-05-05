#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

object book;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Inside the gatehouse");
    set( "long", @EndText
You are in what looks like th old gatehouse. Long ago this used to
house the pully machine that raised and lowered the gates of the
town. You can still see bits and pieces of it. There isn't much
else to this room except a few dust covered books, and a window.
There is also a stairway leading up.
EndText
    );
    set( "exits", ([
      "east" : RM+"rm2.c",
      "up" : RM+"gatehouse2.c",
    ]) );
    set("item_desc", ([
      "bits and pieces" : "Mostly old rusted junk, nothing of intrest.\n",
      "bits" : "Old rusty metal, and tattered wire.\n",
      "pieces" : "Screws and whatnot.\n",
      "tattered wire" : "IT dosen't look usable.\n",
      "wire" : "It dosen't look usable.\n",
      "screws" : "Those things you screw things with, nothing special.\n",
      "metal" : "Old and rusty, nothing useful.\n",
      "whatnot" : "Nothing of intrest.\n",
      "junk" : "Junk, just junk.\n",
      "books" : "Old and worn books, one of them looks readable.\n",
      "stairway" : "It goes up.\n",
      "book" : "It's titled The Dragon, you could grab it.\n",
      "window" : "Nice view, there's a field of wheat.\n",
      "gatehouse" : "Your in it, if you left, you wouldn't be.\n",
      "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
void init(){
    add_action("grab", "grab");
    add_action("climb", "climb");
    add_action("propain", "open");
}

int grab(string str){
    if(!str){
	write("Grab what?\n");
	return 1;
    }
    if (str == "book"){
	write("You grab the book and blow the dust off.\n");
	book = clone_object(ITEM+"book.c");
	book->move(this_player());
	return 1;
    }
}
int propain(string str){
    if(!str){
	write("Open what?\n");
	return 1;
    }
    if (str == "window"){
	write("You open the window.\n");
	write("You could climb out if you wanted to.\n");
	return 1;
    }
}
int climb(string str){
    if(!str){
	write("Climb where?\n");
	return 1;
    }
    if (str == "out"){
	write("You climb out the window and enter the wheat field.\n");
	TP->move_player(RM+"field1.c");
	return 1;
    }
    return 1;
}
