#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Seb's Apartment" );
    set("c_long",@EndText
You are in Sebastians personal workroom.  The walls, are etched out of 
of ice, and yet the place is warm.  There are papers scattered about
the place, and a large "Wiz for Dummies" book on the coffee table.  
Taco Bell, and MacDonalds wrappers and cups are strewn about.  There
is a C.D. player here, that you can listen to.  To the east is the 
kitchen.

EndText
    );
    set( "exits", ([
      "start" : START,
      "void" : VOID,
      "east" : "/u/s/sebastian/kitchen.c",
      "bed" : "/u/s/sebastian/bedroom.c",
    ]) );
    set("listen" , "You hear Celtic music play.\n" );
    set("smell", "Smells like day old McDonald's fries and socks.\n");
    set( "item_desc", ([
      "walls" : "They are cool to the touch, considering they are ice.\n",
      "papers" : "Mostly bills and scraps with scribbling on them.\n",
      "book" : "It is closed and clasped with an unlockable lock.\n",
      "wrappers" : "Mmm...greasy...\n",
    ])  );
}
void init() {
    ::init();
}
