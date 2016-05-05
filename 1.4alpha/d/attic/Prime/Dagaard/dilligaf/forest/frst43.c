#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short" , "A forest path");
  set( "long" , @EndText
  You have come to a small intersection, there really isn't much to
  see here, just a bunch of trees and few bushes that line the path.
  Off to the south you can see the beginings of a magnificent city,
  a large golden gate shines brightly and you can see the outlines
  of some town guards. In the bushes you can see a small sign, and
  far to the north high above the trees, you can see the very tips
  of two massive towers.

EndText
  );
  set( "exits", ([
    "north" : FOREST+"frst32.c",
    "south" : "/d/Prime/Krynn/Duegne/gates4.c",
  ]) );
  set("item_desc" , ([
    "trees" : "Large trees.\n",
    "bushes" : "Bushes.\n",
    "path" : "You wonder if you should stay on it.\n",
    "sign" : "You brush aside some of the bushes' leaves and start to make out some of the words...slowly you descern a message.\n",
    "tower" : "You can't see it too well from here.\n",
    "towers" : "You can't see them too well from here.\n",
    "gate" : "It shines brightly, but you need to get closer to see any detail.\n",
    "guards" : "You can't really see them from here.\n",
    "guard" : "You can't really see them from here.\n",
    "message" : "Maybe you should read it?\n",
  ]));
}
void init(){
  add_action("read_func" , "read");
}
int read_func(string str){
  if(!str){
    write("Read what?\n");
  return 1; }
  if(str == "message"){
    write("You brush aside the leaves and see a message come about. It says 'Beware the Thieve's Forrest...stay on the path....this is your only warning.\n");
    say(TPN+" reads the sign and gasps.\n");
  return 1;
  }
  return 0;
}
