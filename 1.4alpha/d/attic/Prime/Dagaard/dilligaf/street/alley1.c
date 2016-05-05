#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "An alley");
  set( "long" , @EndText
  You step foot into the blackness of the alley. An overpowering aroma
  of urine and who knows what else assaults your nose. There is trash
  everywhere, its almost as if the whole city dumps their trash here.

EndText
  );
  set( "exits", ([
    "east" : STREET+"street13.c",
    "south" : STREET+"alley2.c",
  ]) );
  set("item_desc" , ([
    "trash" : "Piles of it. Its everywhere.\n",
    "piles" : "Trash. Its just trash.\n",
  ]));
}
