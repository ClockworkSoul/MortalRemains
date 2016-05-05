#include "maze.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
int key_here;

void create()
{

object ob1;
    
    ::create();

    seteuid( getuid() );
    set( "light", 1 );
    key_here = 1;
    set("author","blood");
    set( "short", "The Maze" );
    set( "long", @EndText
You are in a room which appears to have no ceiling, floor or walls,
however twisting prisms of light surround you, shifting in color and size.
A low humming can also be heard, at the edge of your senses.  You also can
smell the strong sent of sweat.  This must be the past frustration of
other adventurers who have tried the way of the maze.
 
EndText
    );
    set("item_desc", ([
"prisms" : "The prisms appear to be what is supporting you, and the\n"+
"structure of this area.  You wonder if something else might be in \n"+
"the prisms with you. Whatever you do, don't try and disrupt magics,\n"+
"here.\n",
    ]) );
    
  ob1 =  clone_object("/std/coins");
  ob1 -> credit(random(5) + 1);
  ob1 -> move(this_object());

    set( "exits", ([
      "west" : MAZE+"maze3.c",
      "south" : MAZE+"maze17.c",
      "southeast" : MAZE+"maze18.c",
      "southwest" : MAZE+"maze1.c"
    ]) );
}

void init() {
  add_action("search", "search");
} 
  int search(string str) {
    object key;
  
  if(str=="prisms") {
    if(key_here) {
      key=clone_object(MAZE+"lightkey.c");
      key->move(TP);
      write("You find a key hidden here!\n");
      say(TPN+" searches the prisms.\n");
      key_here=0;
      return 1;
}
return 0;
}
} 
