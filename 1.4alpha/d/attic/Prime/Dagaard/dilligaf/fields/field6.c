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
    "east" : FIELDS+"field7.c",
    "west" : FIELDS+"field5.c",
    "north" : FIELDS+"field13.c",
  ]) );
  set("item_desc" , ([
    "fields" : "Golden fields all around you.\n",
    "wheat" : "Golden fields all around you.\n",
  ]));
reset();
}
