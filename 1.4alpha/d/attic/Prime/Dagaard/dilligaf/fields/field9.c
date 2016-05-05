#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "Some fields");
  set( "long" , @EndText
  You stand about waist high in some wheat fields. You can hear surrying
  all around you and wonder what kind of life lives in here.

EndText
  );
  set( "exits", ([
    "east" : FIELDS+"field10.c",
    "south" : FIELDS+"field2.c",
    "north" : FIELDS+"field16.c",
  ]) );
  set("item_desc" , ([
    "fields" : "Golden fields all around you.\n",
    "wheat" : "Golden fields all around you.\n",
  ]));
reset();
}
