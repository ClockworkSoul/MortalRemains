// Coded by Highlander, with some help from Chronos's Object Maker.  :)
#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "-=Sargeras Road=-");
  set("long", @ENDLONG
The inhabitants of Cho'gall wander aimlessly around you as you stand 
in the middle of Sargeras Road.  The Town Square is just to the north,
and farther down the road to the south, through the trees, you can see 
some sort of shrine.  You feel very uneasy staring at the structure,
and want to look away, but you feel drawn to it.
ENDLONG
  );
  set("light", 1);
  set_outside("zone","2");
  set("exits", ([
    "north" : HIGHRM"/town_square.c",
     "west":HIGHRM"/house4.c",
    "south" : HIGHRM"/ss2.c",
  ]) );
  set("item_desc", ([
    "inhabitants" : @ENDDESC
People of several different races can be seen, although it strikes you that none are human
ENDDESC
  ,    "road" : @ENDDESC
Made of the same blood-colored stone as the rest of the roads in town
ENDDESC
  ,    "town square" : @ENDDESC
Looking north, you can see the town square, and the giant statue in the middle.
ENDDESC
  ,    "trees" : @ENDDESC
They are gnarled, dead looking trees.
ENDDESC
  ,    "shrine" : @ENDDESC
The trees obscure most of your view of the shrine, all you can make 
out is a general outline.
ENDDESC
  ,    "engraving" : @ENDDESC
The names of soldiers killed in battle are engraved on the path as a memorial.
ENDDESC
  ,  ]) );
  set("search_desc", ([
    "road" : @ENDDESC
Peering intently at the road you notice a small engraving on each stone.
ENDDESC
  ,  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
