#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", " Entrance Hall (n,s,e,w)");
    set( "long", @EndText
You are in a huge entrance hall. The floor is covered with
white marble and wooden tiles.  The towering walls
are decorated with paintings, and there is a small table
against the north wall beside a door. There is also a
door to the south. The hall continues to the east from
here, and the castle exit is to the west.
EndText
    );
    set( "exits", ([
"north" : "/d/Arctic/Shya/rooms/castle/wall1.c",
      "east" : "/d/Arctic/Shya/rooms/castle/eh2.c",
      "west" : "/d/Arctic/Shya/rooms/room3.c",
	"south" : "/d/Arctic/Shya/rooms/castle/eh3.c"
    ]) );

    set( "item_desc", ([
            "hall": "The sheer size of it makes you feel insignificant.\nThe person who lives here is obviously very rich.\n",
            "floor":"It is made of alternating white marble and wooden tiles, forming a\ncheckerboard pattern. Each one about two feet (.6m) across.\n",
            "marble tiles":"It is a white marble with golden veins. Very nice, and probably quite\nexpensive.\n",
            "wood tiles":"A strong, sturdy oak. Covered in several layers of varnish.\n",
            "tiles" : "Wooden and white marble.\n",
            "walls":"They are probably 15 feet tall. On them are paintings.\n",
            "paintings":"They are of obvious nobility. Perhaps kings. They each wear the same\n crown and each carry the same sceptre.\n",
            "exit":"The door leading out of the castle.\n",
            "checkerboard":"The floor resembles a checkerboard,  and could possibly be used for \none if the pieces were very large.\n",
            "pattern":"An alternating white and brown checkerboard pattern.\n",
            "veins":"Probably gold.\n",
            "varnish":"Applied by a master\n",
            "crown":"The crown in the paintings is gold, with inset gemstones.\n",
            "sceptre":"The sceptre in the paintings is a golden rod with a large blue gem\non the top, and a small red ruby on the bottom.\n",
            "key":"A small brass key\n",
            "table":"This table stands about waist high and made of cherry wood.\n",    
	      "door" : "This door leads to the south into another room.\n",
	      "north wall" : "Probably 15 feet tall with a table next to it.\n", 
	      "nobility" : "Perhaps kings.\n",
		"gems" : "Red rubies and blue sapphires.\n" 
]));

     frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
     frostguard->move(this_object());

}
