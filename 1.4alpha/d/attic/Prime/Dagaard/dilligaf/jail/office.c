#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A jailhouse office");
  set( "long" , @EndText
  A small office that leads into the cell area of the prison. A small desk situates
  itself at the back end of the office, and a rough little chair is there too. The
  desk is litterally cluttered with loads of papers and warrants and other crap
  that just seems to have been thrown there all willy-nilly. Not a very well kept
  office, so you can only imagine how the cells look. 

EndText
  );
  set( "exits", ([
    "south" : STREET+"street20.c",
  ]) );
  set("item_desc" , ([
    "desk" : "A cluttered desk.\n",
    "chair" : "Very twisted due to the Sheriff's immense bulk.\n",
    "sheriff" : "Do you see him here?\n",
    "papers" : "Lots of them...\n",
    "warrants" : "Lots of them...\n",
    "crap" : "Uhh...its crap...not really but could be...\n",
    "cells" : "You can see them through the doorway to the east.\n",
    "doorway" : "A large forcefield guards the doorway.\n",
    "forcefield" : "You wonder how to get past that thing...\n",
    "lever" : "Hrm...wonder what happens if you pull it...\n",
  ]));
}
void init(){
    add_action("search_func" , "search");
    add_action("yank_func" , "pull");
}
int search_func(string str){
  if(!str){
    write("What would you like to search?\n");
  return 1;
}
  if(str=="papers"){
    write("You rifle through the papers and find a lever!\n");
    say(TPN+" rifles through some papers and finds something!\n");
  return 1;
 }
  return 0;
}
int yank_func(string str){
  if(!str){
    write("Pull on what?\n");
    return 1;
  }
  if(str=="lever"){
    write("You yank hard on the lever and 6 guards jump out and throw you in prison...naked as a jaybird.\n");
    say(TPN+" pulls back on the lever and is set upon by guards!\n");
    this_player()->move_player("/d/Prime/Dagaard/dilligaf/jail/jail1.c");
  return 1;
  }
return 0;
}
