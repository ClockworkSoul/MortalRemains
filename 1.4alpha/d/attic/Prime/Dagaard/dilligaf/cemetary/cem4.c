#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "wraith" : MON+"wraith.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "A graveyard");
  set( "long" , @EndText
  You stand in front of the entrance to a very large keep. Where the
  hell did this come from...you have no idea...but its here. There is
  no sound, and the raught iron black gate that stands before you has
  an image of a Knight in battle with a Dragon. Tombstones are scattered
  everywhere across the path, utter destruction would be the word.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"cem3.c",
    "west" : CEMETARY+"cem8.c",
  ]) );
  set("item_desc" , ([
    "keep" : "It is a large and very forboading place...do you really want to go in there?\n",
    "gate" : "Its very large, and very locked.\n",
    "image" : "A knight in a ferocious battle with a dragon. There is an inscription.\n",
    "inscription" : "'And so Lord Soth perished, and with him he took all the fires of Hell.'\n",
    "tombstones" : "There is writing on one of them.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
    "knight" : "Lord Soth in heated battle with a Dragon.\n",
    "dragon" : "A very large black dragon in heated combat with Lord Soth.\n",
  ]));
reset();
}
void init(){
  add_action("read_func" , "read");
  add_action("yell_func" , "yell");
}
int read_func(string str){
  if(!str){
    write("What would you like to read?\n");
  return 1; }
  if(str == "writing"){
    write("'Here lies an adverturer who yelled 'Let me in''\n");
  return 1; }
return 1; 
}
int yell_func(string str){
  if(!str){
    write("Yell what?\n");
  return 1; }
  if(str == "let me in"){
    write("You yell and are transported to the other side of the gate.\n");
    say(TPN+" dissapears from your sight, only to reappear on the other side of the gate.\n");
  this_player()->move_player("/d/Prime/Dagaard/dilligaf/cemetary/keep1.c");
  return 1; }
return 1;
}
