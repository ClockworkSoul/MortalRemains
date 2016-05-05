#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "A small forest path");
  set( "long" , @EndText
  You are standing on a small forest path. It continues southeast in
  to the woods, and another path leads south towards a forboading
  gate. You can hear birds and other happy creatures in the forest,
  while all sound dies off to the south. You can just make out the
  borders of a wooden sign in the bushes.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street1.c",
    "south" : CEMETARY+"cem1.c",
    "southeast" : FOREST+"frst2.c",
  ]) );
  set("item_desc" , ([
    "gate" : "You can't see it very well from here.\n",
    "forest" : "You can't see it very well from here.\n",
    "woods" : "You can't see it very well from here.\n",
    "sign" : "Perhaps you should read it.\n",
  ]));
}
void init(){
  add_action("read_func" , "read");
}
int read_func(string str){
  if(!str){
  write("Read what?\n");
  return 1; }
  if(str == "sign"){
    write("You brush away some of the vines covering the sign and start to make out some of the words inscribed on it. 'Beware to the south...the undead live within.'\n");
    say(TPN+" read the sign.\n");
  return 1;
}
return 1;
}

