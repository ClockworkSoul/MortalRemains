#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;


void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Intersection of Henderson and Crumple");
  set( "long" , @EndText
  You are standing at the intersection of Henderson and Crumple. 
  There are people milling about on this street. They all seem to
  have some kind of pressing business. To the north there is a strange
  looking door with a sign just above it.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street19.c",
    "south" : STREET+"street21.c",
    "north" : JAIL+"office.c",
  ]) );
  set("item_desc" , ([
    "people" : "People.\n",
    "sign" : "'Dagaard Jail House'\n",
  ]));
}
