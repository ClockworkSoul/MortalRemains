
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
    "up" : PATH+"room4.c",
    "south" : PATH+"room8.c",

  ]) );

}
