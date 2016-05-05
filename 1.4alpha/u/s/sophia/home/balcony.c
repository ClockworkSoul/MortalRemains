#include "sophia.h"
inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "The granite balcony" );
    set("long", wrap(
	"You step out onto a balcony of gray granite with veins of "+
	"pink quartz running through it. It seems to be carved from one solid "+
	"piece of stone and you wonder how it stays up. It is bordered "+
	"by a wrought iron railing and there is are inviting chairs and "+
	"a table here also. "
      ) );
    set("item_desc",([
      "railing" : wrap("Black wrought iron has been twisted into "+
	"a pattern of ivy vines and leaves. A thick cap rail looks "+
	"strong enough to sit on and hang your legs in the trees. "),
      "granite" : wrap("A subtle gray stone that has no business "+
	"being here. It resembles nothing in the area and you cannot "+
	"imagine how it got here. "),
      "chairs" : wrap("These chairs look to be made of the same "+
	"wrought iron as the table and railing and you can't place "+
	"it but it seems sonehow different. "),
      "table" : wrap("Black wrought iron to match the railing and "+
	"chairs. "),
    ]) );
    set( "exits", ([
"in" : HOME+"library.c",
    ]) );
}
void init() {
    add_action("rest", "rest");
    add_action("soar", "soar");
}
int rest(string str){
    if (!str){
	write("Rest where, sweetie?\n");
	return 1;
    }
    if (str == "in chair") {
	write(
	  "The chair wraps around you magically and molds to your "+
	  "every contour.  You have rarely felt so comfortable.\n");
	say(TPN+" sits down and relaxes.\n");
	return 1;
    }
}

int soar(string str){
    if (!str){
	write(
	  "For a split second you atart to drop and then you are blinded "+
	  "by a suddenly silvery sparkle.  When you open your eyes you see "+
	  "two small faeries guiding you. A quick tour around the garden "+
	  "and a peek in a hummingbird's nest and you are gently settled "+
	  "back in Sophia's arms.");
	return 1;
    }
}
