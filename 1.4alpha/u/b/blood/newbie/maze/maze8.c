#include "maze.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;  
    
void create()
{   
    
object ob1;
    
    ::create();

    seteuid( getuid() );
    set( "light", 1 );
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
"structure of this area.  whatever you do, don't try and disrupt\n"+
"magics, here.\n",
    ]) );
    
  ob1 =  clone_object("/std/coins");
  ob1 -> credit(random(5) + 1);
  ob1 -> move(this_object());

    set( "exits", ([
      "up" : MAZE+"maze9.c",
      "west" : MAZE+"maze22.c",
      "north" : MAZE+"maze7.c"
    ]) );
}
