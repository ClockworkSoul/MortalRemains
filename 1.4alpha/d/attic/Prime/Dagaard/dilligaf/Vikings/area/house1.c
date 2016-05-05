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
  set("short" , "Inside a Viking house");
  set( "long" , @EndText
  You stand inside the doorway of a decievingly large house. Placed
  square in the middle of the room is a large wooden table with 5 or 6
  flagons of mead overflowing onto it. Towards the back of the house,
  you can see the brick stove that heats this place. You wonder about
  the decor, large axes and animal heads decorate the walls. There is
  a doorway in the back of the house with a small sign on it.

EndText
  );
  set( "exits", ([
    "east" : ICE+"ice3.c",
  ]) );
  set("item_desc" , ([
    "sign" : "Maybe you should read it.\n",
    "flagons" : "Full to the brim with Mead.\n",
    "flagon" : "Full to the brim with Mead.\n",
    "table" : "Everything in here seems to be made of wood.\n",
    "axes" : "Extremely large and extremely sharp axes. They look like they could split just about anyting...including your head.\n",
    "head" : "Wolves heads mostly, and lots of them.\n",
    "stove" : "A cheery little fire burns inside the oven, heating the room nicely.\n",
    "mead" : "A thicker, honey type beer.\n",
    "heads" : "Wolves's heads mostly, and lots of them.\n",
  ]));
  create_door("east","west","A large wooden door","closed","");
reset();
}
void init(){
  add_action("read_func","read");
}
int read_func(string str){
  if(!str){
    write("What would you like to read?\n");
  return 1;
  }
  if(str == "sign"){
    write("The sign reads 'Freezer', so you open it...and immediatly wish you hadn't. Outside in the snow are what looks to be the corpses of every living animal in the Icelands. Skinned and headless, blood and bones blanket the 'back yard'. You wonder what its all for...if there is a 'cold season' where these people have to harvest and store food...you really don't want to be here for that.\n");
    say(TPN+" opens the backdoor, then shuts it quickly.\n");
  return 1; }
return 1;
}
