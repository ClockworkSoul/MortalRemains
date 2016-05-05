#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

int camel;
object stone;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Abbey Road");
    set( "long", @EndText
You are or were walking on what was a cobblestone walk, now it seems
to be just a cobblestone here and there. To the east stands an old
Abbey, the main road is back west. The backs of buildings are to
the south, while the walls of the town are to the north.
EndText
    );
    set( "exits", ([
     "west" : RM+"AR3.c",
     "east" : RM+"AR5.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "cobblestones" : "Scattered here and there, one looks odd.\n",
     "odd stone" : "It's seems to glow with a faint yellow light.\n",
     "odd cobblestone" : "It seems to glow with a faint yellow light.\n",
     "cobblestone" : "Which one?\n",
     "odd" : "It seems to glow with a faint yellow light.\n",
     "odd one" : "It seems to glow with a faint yellow light.\n",
    ]) );
}
void init() {
   add_action("BooYa", "get");
  }
int BooYa(string str){
   if(!str) {
     write("Get what?\n");
   return 1;
  }
if (str == "stone") {
  if(camel == 1) {
   write("It dosen't look that neat, you toss it away.\n");
  return 1;
 }
     write("You reach down and grab the cobblestone.\n");
     stone = clone_object(ITEM+"stone.c");
     camel ++;
     stone->move(this_player());
   return 1;
 }
return 0;
}
void reset() {
   camel = 0;
   ::reset();
}
