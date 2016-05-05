
#include <config.h>
#include "area.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "author", "Enzyme" );
  set( "light", 1 );
  set( "short", " " );
  set( "long", @EndText

EndText
  );
  set("item_desc", ([
        "blah" : "A short description of blah.\n",
        "blah2" : "A short description of blah2.\n",
  ]) );
  set( "exits", ([
    "north" : PATH+"room12.c",
    "west" : PATH+"room14.c",
    "east" : PATH+"room15.c",

  ]) );

}
