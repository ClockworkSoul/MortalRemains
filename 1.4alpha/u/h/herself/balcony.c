
// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set("author", "Herself");
    set ("short" , "The Balcony");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("long", wrap(
	"As you walk out onto the balcony, the sunlight "+
	"catches the windchime hanging from the left "+
	"side of the balcony. The light shimmers and "+
	"you are momentarily blinded. You stumble, "+
	"afraid that you will fall over the side, but "+
	"you reach the far edge and safely hold onto the guard "+
	"rail. The sunlight and fresh air completely relaxes "+
	"you. Looking down you see the enormous plush yard. "
      ) );
    set("item_desc", ([
      "down" : wrap("You peer over the side of the balcony and "+
	"you feel yourself almost start to fall again. "+
	"The ground seems to move, inviting you to jump "+
	"over the edge. The view is so ixhilarating that you "+
	"begin to think you could fly. You climb up onto the side "+
	"of the railing and look all around. You see clouds "+
	"surrounding you. A bird flies past your face, and "+
	"you are brought out of the dreamlike state. Slowly, "+
	"you climb down off the railing, and eventually your "+
"breathing returns to normal. "),
      ]) );
    set( "exits", ([
"doors" : "/u/h/herself/bedroom.c"
    ]) );
}
