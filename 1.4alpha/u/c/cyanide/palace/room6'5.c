#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set( "light", 1 );
set("area_type", ([
"black" : 2,
]) );
set("short", "Grand Plaza");
  set( "long", @EndText
Huge stone basins such as those used for topiaries surround
the plaza, but beneath the dust there is only black ash. A
large crack cuts through the plaza and extends to the palace
beyond. The crack is quite deep, and dust and and has gathered
in its depths, but does not fill or cover it over. Many
skeletons are visible, partially buried in dust.
EndText
  );
set("arena", 1);
  set( "exits", ([
"east" : MAIN+"/room8'5.c",
"west" : MAIN+"/room5'5.c",
"south" : MAIN+"/room7'4.c",
  ]) );
set ("item_desc", ([
  "basins" : "They are made of some kind of porous stone. They are\n"+
     "cracked beyond any kind of use.\n",
  "crack" : "If you tried to enter it, you would probably suffocate.\n",
  "dust" : "It is dusty, fool.\n",
  "ash" : "It looks like something was once burned here.\n",
  "skeletons" : "They are the skeletons of the dwarven inhabitants of this\n"+
                "ancient city. It appears that they have alrady been looted.\n",
   ]) );
}

void init () {
add_action("crack_func","enter");
}

int crack_func(string str) {
  if (str!="crack" && str!="crevasse") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write (
    "Throwing caution to the wind, you decide to climb on in...\n"+
    "The last thought before the dust fills you lungs is of your own
foolishness.\n"+
    "\nYou fool.\n");
  say (
    NAME+" climbs into the huge crack, and dissapears into the dust.\n");
  this_player()->move(MAIN+"/vault.c");
  this_player()->set("hit_points", -10);
    return 1;
  }
