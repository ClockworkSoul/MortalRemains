#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A workroom" );
  set( "long", @EndText
room
EndText
  );
  set( "item_desc", ([
  ]) );
  set( "exits", ([
      "workroom" : "/u/r/rislyn/workroom.c",
  ]) );
}


