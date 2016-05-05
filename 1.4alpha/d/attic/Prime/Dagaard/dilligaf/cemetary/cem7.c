#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "ghost" : MON+"ghost.c"]) );
  reset();
  set("light" , 1);
  set("short" , "A graveyard");
  set( "long" , @EndText
  You have stumbled into the Dagaard cemetary. There are tombstones
  everywhere and you wonder exactly how many people are buried here.
  There is a path that leads through the tombstones and off to the
  south you can see a very large building.

EndText
  );
  set("exits" , ([
    "north" : CEMETARY+"cem6.c",
    "south" : CEMETARY+"cem8.c",
    "east" : CEMETARY+"cem3.c",
  ]) );
  set("item_desc" , ([
    "building" : "You can't see it very well from here.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "tombstones" : "You can see fresh remains of a grave.\n",
    "dirt" : "Loose dirt.\n",
    "grave" : "A small grave, the dirt around it seems to be a bit loose.\n",
  ]));
reset();
}
void init(){
  add_action("search_func" , "search");
}
int search_func(string str){
  if(!str){
    write("What would you like to search?\n");
  return 1; }
  if(str == "grave"){
    write("You search the grave, and are transported elsewhere.\n");
    say(TPN+" dissapears before your eyes.\n");
  this_player()->move_player("/d/Prime/Dagaard/dilligaf/cemetary/grave1.c");
  return 1; }
return 1;
}
