#include "newbie.h"
#include <config.h>
#include <mudlib.h>
    
inherit ROOM;
int flute_here;
    
void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    flute_here = 1;
    set( "short", "Meditation Chamber" );
    set( "long", @EndText
A deafening silence assaults your senses as you enter this room. A soft
ambient light resonates from every part of the room. Lush carpeting and soft
mats cover the floor and walls, and the ceiling depicts a star specked sky
with voids as black as the night in between.

EndText
    );
    set("item_desc",([
        "mats" : "The mats have a very hard surface, with soft padding to
prevent injury.\n",
    ]) );
    
    set( "exits", ([  
         "south" : N_ROOM+"room8.c",
    ]) );
}   
    
void init() {
  add_action("lift", "lift");
}
  int lift(string str) {
      object flute;
  if(str=="mat") {
  if(flute_here) {
    flute=clone_object("/d/Prime/Magehouse/items/flute.c");
    flute->move(TP);
    write("You find a flute beneath the mat and grab it quickly!\n");
    say(TPN+" lifts a mat.\n");
    flute_here=0;   
    return 1;
}
return 0;
}
}
