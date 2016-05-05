#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Living Room" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The walls are completely coverd in posters of his fave bands.  There is
 a stereo in here as well.  There are couches along two walls, and a table
on the other.  To the north is the kitchen, to the west is Stan's
room.

EndText
    );
    set( "exits", ([
"north" : "u/s/sebastian/kitchen.c",
"west" : "u/s/sebastian/Stansroom.c",
"up" : "u/s/sebastian/bedroom.c",
    ]) );
	set("listen","I ought to praise you like I should..\n");
set("item_desc" , ([
	"walls":"Walls? what walls? You can only see the posters.\n",
	"posters":"Everything from Barenaked Ladies to Slayer, you\n"+
	" name it, it's here.\n",
	"stereo":"It's busted, and just keeps repeatingOC that song by\n"+
	" Fat Boy Slim over and over.\n",
	"couches":"They are made of the finest NewbieHide Leather!\n",
	"table":"The table is filled with books.\n",
	"books":"A whole bunch of role playing supplements.\n",
	])   );
}
