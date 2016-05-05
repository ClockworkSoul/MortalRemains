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
  set("objects" , ([ "wraith" : MON+"wraith2.c"]) );
  reset();
  set( "light", 1 );
  set("short" , "Lord Soth's Keep. [3rd Floor]");
  set( "long" , @EndText
  You have reached a dead-end. The creature that lives here doesn't
  keep a very nice home. The walls and the ceiling are black with
  a sort of black soot, and the window in the west wall is just as 
  black.

EndText
  );
  set( "exits", ([
    "up" : KEEP+"keep11a.c",
    "stairs" : KEEP+"keep8.c",
  ]) );
  set("item_desc" , ([
    "cobwebs" : "Thick cobwebs, hope you like spiders.\n",
    "bricks" : "Large blackened bricks, almost soot covered.\n",
    "walls" : "Black with some sort of soot.\n",
    "ceiling" : "You have discovered a door!\n",
    "window" : "You look out the window and wipe away some of the soot, far down from you is the garden surrounding the keep. Off slightly to the west you can make out a large crater in the earth...you wonder what could have made such a hole.\n",
  ]));
  set("exit_suppress" , ({"up"}) );
  set("door_suppress" , 1);
  create_door("up","down","A trap door, cleverly concealed in the soot.","locked","skeleton_key");
}
