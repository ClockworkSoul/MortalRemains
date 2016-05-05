#include <config.h>
#include <mudlib.h>

int dogshit;

inherit ROOM;

#include "../camel.h"

object paper;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "The top of the Gatehouse");
    set( "long", @EndText
You are at the top of the gatehouse. This is where the guards used
to keep watch, since all of the guards were fired, there's not much
use for this room anymore. There are a few papers strewn about, but
not much else.
EndText
    );
    set( "exits", ([
     "down" : RM+"gatehouse.c",
    ]) );
    set("item_desc", ([
     "papers" : "Nothing of note, except one blue piece.\n",
     "floor" : "Uder you, boy are you lucky.\n",
     "blue piece" : "You could grab it, if you wanted to.\n",
    ]) );
}
void init(){
   add_action("grab", "grab");
  }
int grab(string str) {
   if (!str){
     write("Grab what?\n");
   return 1;
  }
if (str == "paper") {
   if(dogshit == 1){
     write("It's blank.\n");
   return 1;
  }
     write("You grab the piece of blue paper.\n");
     paper = clone_object(ITEM+"bluepaper.c");
     dogshit++;
     paper->move(this_player());
   return 1;
 }
return 0;
}
void reset() {
   dogshit = 0;
 ::reset();
}
