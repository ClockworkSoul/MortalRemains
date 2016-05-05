#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
   set( "light", 0 );
  set( "short" , "A very dirty alley");
  set( "long" , @EndText
  You are standing in trash in a very dark alley. The smell is very
  overpowering and you can barely maintain your sanity from the
  stench.

EndText
  );
  set( "exits", ([
    "north" : STREET+"alley1.c",
  ]) );
  set("item_desc" , ([
    "trash" : "You are standing in it and its about knee high.\n",
  ]));
}
void init(){
  add_action("search_func" , "search");
}
int search_func(string str){
 object monster = clone_object("/d/Prime/Dagaard/dilligaf/monster/jacktheripper.c");
  if(!str){
      write("Search what?\n");
    return 1;
  }
  if(str == "trash"){
   if(this_object()->query("cloned_monster") )  return;
    write("You rifle throught the trash, and suddenly you are set upon.\n");
    say(TPN+" rifles through the trash, and is suddenly set upon.\n");
  monster->move(environment(this_player()));
  monster->kill_ob(this_player());
  this_object()->set("cloned_monster" , 1);
  return 1;
}
return 0;
}
