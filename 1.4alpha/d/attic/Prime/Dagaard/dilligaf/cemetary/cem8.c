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
  You are surrounded by tombstones and graves. Off to the east you can
  see a large keep, with a big black gate in front of it.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"cem7.c",
    "east" : CEMETARY+"cem4.c",
    "west" : CEMETARY+"cem8.c",
  ]) );
  set("item_desc" , ([
    "keep" : "A large forboading place.\n",
    "gate" : "You can't make out the details from here.\n",
    "tombstones" : "There is writing on one of them.\n",
    "path" : "A small dirt path that leads through the graveyard.\n",
  ]));
reset();
}
void init(){
  add_action("read_func" , "read");
}
int read_func(string str){
  if(!str){
    write("What would you like to read?\n");
  return 1; }
  if(str == "writing"){
    write("'Try a little to the north.'\n");
  return 1; }
return 1; 
}
