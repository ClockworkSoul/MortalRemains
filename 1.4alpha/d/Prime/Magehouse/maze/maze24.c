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
same old same old, only this time, only exit is back from where you came.
EndText
    );
  
  ob1 =  clone_object("/std/coins");
  ob1 -> credit(random(5) + 1);
  ob1 -> move(this_object());

    set( "exits", ([
      "north" : MAZE+"maze15.c"
    ]) );
}   
