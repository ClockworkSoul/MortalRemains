/*
* FILE: Magog03.c
* DESC:
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
  //add_action("subroutine", "command");
}

void create()
{
  object mon;

  ::create();
  seteuid( getuid() );
  set("author", "gasman");
  set( "light", 1 );
  set( "smell", "" );
  set( "short", "Rue Magog" );
  set("long", wrap(
"You are standing on the west end of Rue Magog. "
  ));

 set("item_desc", ([
      "dome" : "A massive glass dome encases this undersea land.\n",
 ]));

  set( "exits", ([
    "east"  : O_CITY+"magog04",
    "west"  : O_CITY+"magog02",
  ]));

  set("objects", ([ "citizen" : O_MON+"citizen.c" ]));
  ::reset();
}

