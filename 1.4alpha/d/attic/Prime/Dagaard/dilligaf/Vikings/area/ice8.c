#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A graveyard");
  set( "long" , @EndText
EndText
  );
  set( "exits", ([
    "north" : ICE+"ice7.c",
    "south" : ICE+"ice9.c",
  ]) );
  set("item_desc" , ([
  ]));
reset();
}
