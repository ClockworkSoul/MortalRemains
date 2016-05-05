/*
* FILE: tunnel1.c
* DESC: beginning of a tunnel
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

int times = 0;

void init()
{
  //add_action("subroutine", "command");
}

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "smell", "The tunnel smells musty." );
  set( "short", "A glass tunnel.");
  set( "long", wrap( 
       "You are in a glass tunnel deep under the sea. "+
       "From here the tunnel curves down a steep hill. "+
       "with the glass floor you are nervous about headding down. "
  ));

 set("item_desc", ([
      "walls" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
      "wall" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
 ]));

  set( "exits", ([
    "down"  : O_ROOM+"tunnel4.c",
    "west"  : O_ROOM+"tunnel2.c",
  ]));

 set ("pre_exit_func", ([ "down" : "move_down" ]));
}


int move_down(string arg)
{
  switch(times)
  {
   case 0:
     write("\n\nYou take a step an fall, crashing down the tunnel.\n\n");
     times++;
     call_out("move_down", 3);
   break;
   case 1:
     write("As you land you think you hear your neck snap.\n\n");
     this_player()->receive_damage(10, "crushing");
     times = 0;
     this_player()->move(O_ROOM+"tunnel4");
   break;
   }
  return 1;
}
