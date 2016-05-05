#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", "cyanide");
set ("arena" ,1);
set ("light", 0);
set ("short", "Cliff");
  set( "long", @EndText
This is a remarkable spot in the area. Perhaps two hundred feet above
you is a gaping hole in the earth's surface through which pours bright
sunshine! A few seedlings from the world above, nurtured by the sunlight
and occasional rains, have grown into giant trees, making this a virtual
oasis in the desert of the great underground region. To the west is a
sheer precipice, dropping nearly fifty feet to jagged rocks below. The
was south is barred by a forbidding stone wall, crumbling with age. There
is a jagged opening in the wall to the southwest, through which leaks a
fine mist. The land to the east looks lifeless and barren.
A rope is tied to one of the large trees here and is dangling over
the side of the cliff, reaching down to the shelf below.
EndText
  );
  set( "exits", ([
"southwest" : MAIN+"/LOS02.c",
"east" : MAIN+"/barren.c",
"down" : MAIN+"/ledge.c",
  ]) );

set ("item_desc", ([
"trees" : "Mostly oak and pine varieties.\n",
"wall" : "It seems to be more ancient than your civilization.\n",
"hole" : "If only you could get up there.\n",
"precipice" : "To jump would be your death, no doubt.\n",
"rocks" : "If you jumped, they would mean your instant demise.\n",
"mist" : "It seems somehow... evil.\n",
"rope" : "You could use it to go down from here.\n",
"cliff" : "Don't jump!\n",
"seedlings" : "They come in all imaginable forms.\n",
]) );
}

void init () {
add_action ("jump_func", "jump");
add_action ("exits","exits");
}

int exits() {
write ("You begin to get a nasty headache.\n");
say (NAME+" begins to look very confused.\n");
return 1;
}

int jump_func() {
  write (@EndLeap
You take a risk and take a running leap, praying for the best...
Unfortunately, you hit your head on a small outcropping, spin in the air,
and bounce off of a ledge fifty feet below you. In the end, you lie upon
the broken, jagged stone below with your insides torn and broken; your
last thoughts before cold death takes you are those of you own foolishness.

You fool.

EndLeap
  );
  say (NAME+" foolishly steps off of the cliff edge.\n"+
    "You hear a sickening crack below you, and a muffled moan.\n");
  this_player()->move(MAIN+"/ledge.c");
  say (
    "You hear a scram above you, and "+NAME+" falls by you, bounces off the\n"+
    "ledge with a thud, and proceeds to hit the ground below with a sickening\n"+
    "crack!\n");
  this_player()->move(MAIN+"/clbase.c");
  say (
    "You hear a distant scream above you, and suddenly "+NAME+" lands upon the naked\n"+
    "stone with a sickening crack. "+NAME+" mutters something about being cold, and\n"+
    "passes out.\n");
  this_player()->set("hit_points", -10);
return 1;
}
