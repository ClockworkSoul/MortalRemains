#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;

object maker;

void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short", "A mysterious room");
  set( "long", @EndText
Green mist sits along the floor, looking as if it will pounce and devour you
at a moments notice. Other than the mist and a large portal on the northside
of this room, it is all void of any material things. There are no walls, no
ceiling, not even a visible floor. It is as if you are standing on
absolutely nothing. You feel as you walk around that you are not really moving
or that the portal is following you around as you investigate the area.
EndText
  );
  set( "exits", ([
  ]) );
   set ("item_desc", ([
 "portal" : "The shimmering portal seems to follow you around as you move.\n"+
	     "It hums silently as its blueish glow is cast across the\n"+
	     "the green mist, creating a spectacular yet strange color\n"+
	     "mixtures. You can make out an image on the other side of\n"+
	     "the portal, but not in detail. Perhaps you could see what\n"+
	     "is there if you 'enter portal'.\n",
 "mist" : "It creeps up your leg quickly, but is easily shaken off with\n"+
	   "a small kick. The putrid smell is carried with it is enough to\n"+
	   "make your eyes water and force you to plug your nose in disgust\n"
   ]) );
reset();
}
void init(){
add_action("go_in","enter");
}
int go_in(string str){
string msg;
msg = (string)this_player()->query("cap_name") + " steps into the unknown...\n";
if(!str || str != "portal") return 0;
write("You step through the portal.\n");
this_player()->move_player("/u/z/zykor/zyrin/bush1.c", msg);
}
