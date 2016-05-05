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
  set("short" , "Inside Soth's Keep [1rst Floor]");
  set( "long" , @EndText
  You have somehow stumbled into Lord Soth's keep. You stand in awe at
  the main hall. The ceilings in this place are about 120 feet high, and
  at the top burn black candles whose wax seems to dissapear when the
  candle burns low. All along the walls are different suits of armour
  and weapons of every variation. Off to the south you can see a grand
  staircase where the rug that you stand on continues up. Off on the
  sides you can also see doors leading to who knows where. Who ever
  built this place had alot of money, and is very powerful...you wonder
  who or what lives here now.

EndText
  );
  set( "exits", ([
    "north" : CEMETARY+"keep1.c",
    "south" : KEEP+"keep3.c",
    "east" : KEEP+"keep4.c",
    "west" : KEEP+"keep5.c",
  ]) );
  set("item_desc" , ([
    "doors" : "Off to the east and west are sets of double doors that lead out of this room.\n",
    "candles" : "They seem to be magikal. As the wax melts it dissapears and reforms as part of the candle. They never go out.\n",
    "rug" : "A plush red rug with all the frills worn off.\n",
    "wax" : "It dissapears and reforms as part of the candle.\n",
    "ceiling" : "Its WAY up there.\n",
    "armour" : "All sorts of different armour. Everything from platemail to leather studded. Its all here.\n",
    "platemail" : "This is truly a magnificent piece of work plates of black metal have been hammered into what you think has to be the most wonderful suit of plate you can imagine. The onyx like surface shines brightly and you think you can see your reflection. On the breast of the plate is an insignia.\n",
    "insignia" : "It is a black rose.\n",
    "breast" : "You want to look at breasts now?\n",
    "leather studded" : "Hardend leather with small brass stubbs protruding from it.\n",
    "weapons" : "All sorts of weapons. Longswords to nunchucks.\n",
    "longsword" : "Dwarven smithies obviously had a hand in making this sword. Its hilt is carved in pure Admantium, and the blade itself looks as if it has been folded over 1000 times and is razor sharp.\n",
    "staircase" : "Its still a little bit away from you.\n",
  ]));
  create_door("north" , "south" , "A large pitch black door","locked","keep_key");
  create_door("east" , "west" , "A large set of double doors" , "closed" , "");
  create_door("west" , "east" , "A large set of double doors" , "locked" , "skeleton_key");
  set("door_suppress",1);
reset();
}
void init(){
  add_action("get_func" , "get");
}


int get_func(string str) {
  if (str=="armor" || str=="armour") {
    write("How can you possible think you could take that?\n");
    return 1;
  }
  if (str=="sword") {
    write("You can't possibly expect to take such a magnificent"+
      " piece of work.\n");
    return 1;
  }

  return 0;    // This happens if str is not sword or armour.
}
