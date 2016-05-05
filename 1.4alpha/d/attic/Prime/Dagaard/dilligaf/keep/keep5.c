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
  set("short" , "A destroyed room");
  set( "long" , @EndText
  You have walked into a large room where it seems the ceiling has
  collapsed. All over this room are stones and bricks. The walls are
  mere shadows of what once was, what possibly could have done such
  damage?

EndText
  );
  set( "exits", ([
    "east" : KEEP+"keep2.c",
  ]) );
  set("item_desc" , ([
    "bricks" : "Clumps of bricks laying in heaps.\n",
    "stones" : "Large stones that seem to have come from the wall, there are some marks on some of them.\n",
    "marks" : "There are some burn marks, and some scratch marks.\n",
    "burn marks" : "Blackend stone and rock...something HOT burned this room down.\n",
    "scratch marks" : "Deep grooves run along some of the stones.\n",
    "ceiling" : "The ceiling has collapsed, but what could have caused it?\n",
    "cavern" : "You peer down into the cavern and wonder if it would be possible to jump down into it.\n",
    "hole" : "You examine the hole a little more and discover that it is actually the entrance to a huge cavern.\n",
    "clumps" : "You think you see something in the clumps of bricks.\n",
  ]));
  create_door("east","west","A large set of double doors","locked","skeleton_key");
reset();
}
void init(){
  add_action("search_func" , "search");
  add_action("jump_func" , "jump");
}
int search_func(string str){
  if(!str){
    write("What would you like to search?\n");
  return 1; }
  if(str == "clumps"){
    write("You search through the bricks and find a hole.\n");
    say(TPN+" sifts through the rubble for a bit.\n");
  return 1; }
return 1;
}
int jump_func(string str){
  if(!str){
    write("Jump where?\n");
  return 1; }
  if(str == "down"){
    write("You would surely die if you attempted such a jump.\n");
    say(TPN+" braces themselves to jump to their death, then decides against it.\n");
  return 1; }
return 1;
}
