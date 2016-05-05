#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short" , "The Center of Towne");
  set( "long" , @EndText
  You are at the Center of Towne. It is the Intersection of Claddagh
  and Henderson. There is a large signpost rammed into the ground.
  This also is the busiest part of the city, people are charging
  around with lots on their minds.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street7.c",
    "south" : STREET+"street13.c",
    "east" : STREET+"street22.c",
    "west" : STREET+"street5.c",
  ]) );
  set( "item_desc" , ([
    "signpost" : "You can see four large boards tacked to the post\n",
    "board" : "Look at which board?\n",
    "boards" : "Look at which boards?\n",
    "board 1" : "Shop: 2n w\n",
    "board 2" : "Pub: 2e n\n",
    "board 3" : "Forest: 5s\n",
    "board 4" : "A small message is written here.\n",
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
    write("Beware the Angel of Death, he comes for you.\n");
    say(TPN+" read the sign.\n");
  return 1; }
return 1;
}
