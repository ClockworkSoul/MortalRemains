#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Crumple Street");
  set( "long" , @EndText
  You stand upon Crumple Street. To the south is a doorway with a
  sign that hangs above it. You can hear the loud crashing and 
  commotion coming from the south. Maybe you could enter the club.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street16.c",
    "east" : STREET+"street18.c",
  ]) );
  set("exit_msg", ([
    "south" : "$N tries to go south, but the bouncers stop them.\n",
  ]) );
  set("item_desc" , ([
    "sign" : "'Club Confetti'\n",
    "doorway" : "Two blackened doors with two large men standing just inside it. There is a small plaque over to one side.\n",
    "plaque" : "Please show your id to the bouncers.\n",
    "men" : "You can't see them too well from here.\n",
  ]));
}
void init(){
  add_action("show_func" , "show");
  add_action("enter_club" , "enter");
}
int show_func(string str){
  if(!str){
    write("Show what to who?\n");
  return 1; }
  if(str == "id to bouncers"){
    write("You show your id to the bouncers and they let you inside.\n");
    say(TPN+" shows their id to the bounders and is let inside.\n");
this_player()->move_player("/d/Prime/Dagaard/dilligaf/street/pub1.c");
  return 1; }
return 1;
}
int enter_club(string str){
  if(!str){
  write("You don't show your id, and so the bouncers place you back on the street.\n");
  say(TPN+" tries to get inside then is thrown back out by the bouncers.\n");
  return 1; }
return 1;
}
