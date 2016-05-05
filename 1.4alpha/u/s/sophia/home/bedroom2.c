
#include "sophia.h"
inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "Sophia's bedchamber" );
    set("long", wrap(
	"This comforting room is home to a warm bed and cosy looking "+
	"fireplace.  An ironwood spiral staircase leads up from here. "
      ) );
    set( "exits", ([
"down" : "/u/s/sophia/workroom2.c",
"up" : HOME+"library.c",
    ]) );
    set("item_desc", ([
      "bed" : wrap("A sleigh bed made of ironwood obviously carved "+
	"by a talented hand long ago. Even this wood is worn where "+
	"hands have traced across it for generations. A soft down duvet "+
	"is on the mattress to snuggle under. "),

      "mattress" : wrap("The mattress is soft like its owner and you "+
	"imagine sinking into it if you laid down. A small feather "+
	"peeks out of a small hole where one of the seams is slightly "+
	"worn. Feather pillows rest against the head of the bed and a "+
	"shallow bowl sits on a small table beside the bed. "),

      "feather" : "A small irridescent blue feather.\n",

      "pillows" : wrap("Square pillows covered in needlepoint; crafted "+
	"by a patient hand on winter nights.  They smell like everything "+
	"else around here; like sophia. "),

      "bowl" : wrap("This beaten copper bowl, darkened with age, "+
	"has eleven symbols inscribed around the inside of the "+
	"rim.  It is filled with a dark watery liquid that although "+
	"it beckons you to touch it, you fear to disturb. "),

      "flooring" : wrap("The floor is made of rich warm wood inlaid "+
"to match the fireplace panels. It seems to have small "+
"scratches in it near the fireplace edge. "),

      "fireplace" : wrap("No fire burns here yet but kindling is "+
	"stacked neatly on the grate ready to be lit if anyone feels "+
	"the need for warmth or romance.  The fireplace itself is "+
	"old stone with a beautifully carved mantle and inlaid "+
	"panels that match the flooring. "),
    ]) );
}
void init() {
    add_action("disturb", "disturb");
    add_action("touch", "touch");
    add_action("smell", "smell");
}
int disturb(string str) {
    if (str=="liquid") {
	say(TPN+" seems to see something you don't\n");
	write(
	  "As a slight shock runs up your hand and arm "+
	  "a picture forms and you realize that this is a "+
	  "rare and treasured elven image keeper.  You wonder who it "+
	  "is whose image is kept here.\n");
	return 1;
    }
}

int smell(string str){
    if (!str){
	write("Smell what?\n");
	return 1;
    }
    if (str == "pillows") {
	write(
	  "They smell like Sophia, lavender and of course cookies "+
	  "and...a hint of something else you can't identify. You feel an "+
	  "impulse to hold and smell Sophia.\n");
	say(TPN+" starts looking silly and smelling pillows.\n");
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
	say(TPN+" discovers an exit.\n");
add ("exits", ([ "panel" : HOME+"bathroom.c" ]) );
	return 1;
    }
    return 1;
}
