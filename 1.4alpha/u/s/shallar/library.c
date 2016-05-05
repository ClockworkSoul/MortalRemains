#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    object blackcat;
    object frostguard;

    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "A Library");
    set( "long", @EndText
This is the castle's library.
Books line all the walls from ceiling to floor. 
There is a comfortable chair here with a small lamp on a table beside it.
EndText
    );
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/eh2.c",
      "east" : "/d/Arctic/Shya/rooms/castle/fhall.c",
	"south" : "/d/Arctic/Shya/rooms/castle/throneroom.c"
    ]) );

 set("pre_exit_func", ([
        "south" : "frostguard_check",  
    ]) );
    reset();
    frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
    frostguard->move(TO);

    blackcat = clone_object("/d/Arctic/Shya/monsters/blackcat.c");
    blackcat->move(this_object());
set("item_desc", ([
    "books" : "All the books are well dusted.\n",
    "chair" : "It seems very comfortable.\n",
    "lamp" : "A small kerosene lamp.\n",
    "table" : "A small table with a lamp on it.\n",
    "walls" : "Covered in books makes it hard to tell what it is made of.\n",
    "wall" : "Covered in books makes it hard to tell what it is made of.\n",
    "floor" : "Pretty solid if you are standing on it.\n"
]));
}

int frostguard_check()
{
    if (present("frostguard", TO))
        {
        write("The frost guard blocks your way! He would rather give his life "+
              "than let you pass.\n");
        return 1;
        }
    return 0;
}

void init() {
 add_action("read_func", "read");
}

int read_func( string str ) {
    string name;

    if (!str) {
 write("Read what?\n");
	return 1;
    }

if (str!="book") {
	return 0;
    }

write("You read an enchanting novel about a God and Goddess.\n");
return 1;
}
