
inherit ROOM;
#include "sophia.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "Sophia's bedchamber" );
    set( "long", @EndText
This comforting room is home to a warm bed and cosy looking fireplace.
An ironwood spiral staircase leads up from here.
EndText );
    set( "exits", ([
"down" : HOME+"workroom.c",
"up" : "/u/s/sophia/home/library.c",
      "up" : "/u/s/sophia/library.c",
    ]) );
    set("item_desc", ([
"bed" : wrap("A sleigh bed made of ironwood obviously carved "+
"by a talented hand long ago. Even this wood is worn where "+
"hands have traced across it for generations. A soft down duvet "+
"is on the mattress to snuggle under. "),
	      ]) );
      }
	void init() {
	    add_action("disturb", "disturb");
	    add_action("touch", "touch");
	}
	int disturb(string str) {
	    if (str=="liquid") {
		say(TPN+" seems to see something you don't\n");
		write(
		  "As a slight shock runs up your "+
		  "hand and arm a picture forms and you realize that this is a "+
		  "treasures and rare elven image keeper. You wonder who it is whose "+
		  "image is kept here.\n");
		return 1;
	    }
	}

	int touch(string str){
	    if (!str){
		write("Search what?\n");
		return 1;
	    }
	    if (str == "panel") {
		write("As you touch you discover a secret exit.\n");
		//      say("TPN+" discovers an exit.\n"); 
		say(TPN+" discovers an exit.\n");
		add ("exits", ([ "panel" : "/u/s/sophia/bathroom.c" ]) );
		return 1;
	    }
	    return 1;
	}
