#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
	set( "short" , "Stan's Room" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The walls, wrought from stone, surround you.  Hints of metal ore
and veins stream upon their surfaces. In each corner, there are
ornate pillars, carved from exotic wood.  The stereo is on, loud.  
All along his great big futon bed, there are clothes and a furry
black wolf stuffed animal.  There seems to be a rather large lump
in the middle of the bed.

EndText
    );
    set( "exits", ([
	"east" : "u/s/sebastian/livingroom.c",
    ]) );
set( "item_desc" , ([
	"wolf" : "You pull the cord and it says Awoo!.\n",
	"pillars" : "They seem so real, so lifelike, so bought.\n"+
	"from Sears.\n",
	"walls" : "An odd texture, a mix between rock and flesh.\n",
	"bed" : "It's Stan, he's asleep.\n",
])  );
}
