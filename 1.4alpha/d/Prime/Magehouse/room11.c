#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
    
int pie_here;
    
void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    pie_here = 1;
    set("author","blood");
    set( "short", "Pantry" );
    set( "long", @EndText
When you enter this room smells of food and all the necessary items to
prepare it are here. Spices, mixes, and various other dried and canned
foodstuffs are on the sections of shelves in rows here.

EndText
    );
    set("item_desc",([
      "shelves" : "These are shelves used to store food.\n",
    ]) );

    set( "exits", ([
      "south" : N_ROOM+"room12.c",
      "west" : N_ROOM+"room7.c"
    ]) );
}   
    
void init() {
    
add_action ("search", "search");
}

int search (string str) {
    object pie;
      
if("str==shelves") {  
  if(pie_here) {
  pie=clone_object("/d/Prime/Magehouse/items/pie.c");
  pie->move(TO);
  write("You find a pie on the shelves!\n");
  say(TPN+" finds something on the shelves.\n");
  pie_here=0;
return 1;
}
return 0;
}
}
