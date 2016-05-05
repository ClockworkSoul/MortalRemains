#include "../Prime.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create() {
  seteuid(getuid());
  ::create() ;
  set_outside("Dark");
  set( "light", 1 );
  set ("short", "On An Unnamed Road");
  set( "author", ({ "nightmask", "cyanide" }) );
  set ("short", "On an Ancient Bridge");
  set ("long", @NotNowIHaveAHeadache
You are aewstruck as you walk onto the ancient basalt expanse which
spans the great ravine; a huge flow of lava underneath you, blistering
exposed skin even at this distance. Your eyes water and lungs burn
from the noxious funes assaulting you. For the first time the trees
are sufficiently sparce to give you a full view of the source of the
fiery river: a huge volcano no more than a mile to your west,
belching forth the huge black plumes that choke the sky and causing
the blood-red glow by which you see.
NotNowIHaveAHeadache
   );
  set ("exits", ([
    "north" : D_PRIMER+"/d_road5.c",
    "south" : D_PRIMER+"/d_road7.c",
  ]) );
// set ("outside", "Dark");
  set ("item_desc", ([
"expanse" : "A long, narrow bridge made of black stone.\n",
"ravine" : "It looks to have once been a riverbed",
"flow" : "It is far below you.\n",
"lava" : "It is flowing by very quickly.\n",
"trees" : "There are no trees on the bridge.\n",
"volcano" : "It's magnicient. You wonder what can be found there.\n",
"plume" : "It blankets the sky for as far as one can see.\n",
"fumes" : "You can't see those - you have to smell them\n",
"ash" : "It fills the sky.\n",
"bridge" : "It is an ancient stone bridge, but is seems sturdy.\n",
"writing" : "It reads: \"Cyanide Magical Bridge Co.\".  How odd...\n",
   ]) );

  set ("smell", ([
"default" : "You smell sulfur and burning wood.\n",
"road" : "It smells like dirt, stupid.\n",
"trees" : "Are we going to smell again?\nThey smell like trees.\n",
"castle" : "It's much too far away\n",
"gates" : "You can't smell that from here.\n",
"fumes" : "As you take a deep breath, you keel over, gagging.\n",
"sky" : "That's it - I give up.  I'm leaving!\n",
  ]) );
  set ("listen", ([
"default" : "You hear the flow of superheated rock below you.\n",
]) );
  set ("search_desc", ([
  "bridge" : "There seems to be some writing on it you can examine.\n",
]) );
  set ("chat_delay", 60);
  set ("chat_random", 35);
  set ("room_chats", ({
"You hear a distant rumbling, and the ground shakes a bit.\n",
"Far off, you hear a woman scream for help.\n",
"Your lungs burn.\n",
"You hear a tremendous cracking noise in the distance, followed\n"+
  "by a long rumbling.\n",
"It is getting very hard to breathe here.\n",
"Something moves in the underbrush to your left.\n",
"You begin to feel as though someone was watching you.\n",
"Far off, on the western horizon, a pillar of flame shoots upwards.\n",
  }) );
  }
