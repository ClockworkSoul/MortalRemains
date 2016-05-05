#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
  You stand upon Claddagh Street. To the west you can see the Center
  of Towne, to the east if grows dark and forboding.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street6.c",
    "east" : STREET+"street23.c",
  ]) );
  set("item_desc" , ([
    "center of towne" : "You can't really see it very well from here.\n",
    "east" : "It grows dark, as if there was some sort of spell\n"+
             "blanketing the area.\n",
  ]));
}
