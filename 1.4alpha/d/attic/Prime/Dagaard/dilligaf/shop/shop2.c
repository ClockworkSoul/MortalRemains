#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Main Lobby");
  set( "long" , @EndText
  You stand in the Main Lobby of this burlesque house. Off to the west
  you can make out a stage and what looks like people dancing. You wonder
  what all the commotion is in that room.

EndText
  );
  set( "exits", ([
    "north" : SHOPS+"shop1.c",
    "stage" : SHOPS+"shop3.c",
  ]) );
  set("item_desc" , ([
    "stage" : "You can't see it too well from here.\n",
    "people" : "People socializing. Actually they look rather\n"+
    "excited to be here.",
  ]));
}
