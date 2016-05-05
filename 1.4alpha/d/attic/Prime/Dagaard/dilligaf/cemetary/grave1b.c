#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

object ob1;
int dug = 0;   //The variable "dug" defined here and set to 0...

void create()
{
  ::create();
  seteuid(getuid());
  set("light" , 0);
  set("short" , "A shallow grave" );
  set( "long" , @EndText
  You have fallen in a small grave that seemingly has no exits. You
  can see shovel marks in the dirt, and the clumps of earth that lie
  on the ground are ominous of a freshly dug hole.

EndText
  );
  set( "exits", ([
  ]) );
  set("item_desc" , ([
    "walls" : "Maybe you could climb them.\n",
    "dirt" : "Its everywhere, I mean you are in a grave.\n",
    "hole" : "The grave that you are standing in happens to be a hole in the ground.\n",
    "marks" : "You examine the marks carefully and think that you can see a slight glint of steel in one of the marks.\n",
    "glint" : "A glint, like as if something was buried in the dirt, maybe you should dig for it.\n",
  ]));
reset();
}
void init(){
  add_action("climb_func" , "climb");
  add_action("dig_func" , "dig");
}
int climb_func(string str){
  if(!str){
    write("Climb what?\n");
  return 1; }
  if(str == "walls"){
    write("You climb out of the grave.\n");
    say(TPN+" climbs up out of the grave.\n");
  this_player()->move_player("/u/d/dilligaf/cemetary/cem7.c");
  return 1; }
return 1;
}

/*
int dig_func(string str){
  if(!str){
    write("You dig in the earth and come out with a key!\n");
    ob1 = clone_object("/u/d/dilligaf/keys/key1.c");
    ob1->move(this_player());
  return 1; }
return 1;
}
*/

int dig_func(string str) {
  say(TPN+ " digs around in the dirt.\n");
  if (dug==0) {
    write("You dig in the earth and come out with a key!\n");
    ob1 = clone_object("/u/d/dilligaf/keys/key1.c");
    ob1->move(this_player());
    dug = 1;   //Sets dug to 1, because he dug.  ;)
  } else {
    write("You find nothing but more dirt.\n");
  }
  
  return 1;
}
