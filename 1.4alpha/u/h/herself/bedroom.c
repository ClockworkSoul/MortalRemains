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
    set("short", "The Bedroom");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("long", wrap(
	"The master bedroom. A brilliant chandelier sparkles "+
	"overhead, giving the illusion of tiny rainbows "+
	"all around the walls and on the bed. "+
	"The closet is on the left across from a roaring "+
	"fire in the fireplace. Candles burn all around, and "+
	"the scent of vanilla and lavender fills the room. "+
	"The portal leads you to the moonwalk, and "+
	"french doors can be opened to go out on the balcony. "
      ) );
    set("smell" , "Lavender and vanilla, a pleasing scent. \n");
    set("objects" , ([
      "bed" : "/u/h/herself/obj/mybed.c",
    ]) );
    reset();
    set("exits", ([
      "down" : "/u/h/herself/workroom.c",
      "portal" : "/u/n/nsd/clown/fair/moonwalk.c",
    ]) );
    set("item_desc", ([
      "fireplace" : "The fire seems to be dying out. \n",
      "walls" : "They are clean and white. \n",
      "closet" : wrap("Rows of shoes line the bottom of the closet "+
	"floor.  Dresses and shirts are hung neatly from brass "+
	"hangers. On the shelf you can see sweaters stacked and sorted by color. "+
	"Hey did you expect it to be messy?"),
      "doors" : "They are french doors, maybe you should open them. \n",
    ]) );
}
void init() {
    add_action("open" , "open");
}
int open(string str) {
    if(str=="doors"){
	say(TPN+ "opens the french doors to the balcony. \n");
	write("You swing the french doors open and look out onto the balcony. "+
	  "It seems to call you outward. \n");
	add("exits", (["out" : "/u/h/herself/balcony.c" ]) );
	return 1;
    }
    return 1;
}
