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
  set("short" , "In front of a small fire");
  set( "long" , @EndText
  You stand just to the east of the main gate. Just inside the fence
  near the east wall of the keep. Swarming around a fire are 3 large
  men trying to keep themsleves warm, though you'd swear that it would
  be easier if they wore more clothing. They wear large fur cloaks and
  have wolf skulls on their heads for helmets. Each has a large beard
  and its braids are all matted together from the wet and cold of the
  environment. Perhaps it is not so much the elements that makes you
  feel this way, but you sure feel warmer than these guys.

EndText
  );
  set( "exits", ([
    "west" : ICE+"ice2.c",
  ]) );
  set("item_desc" , ([
    "braids" : "Long strands of hair, carefully braided. Each one is told to be a mark of accomplishment and bravery.\n",
    "fire" : "It burns rather low for such a climate. You begin to wonder about the constitution of these people.\n",
    "wolf skulls" : "Obviously trophies of some kind, proudly displayed on the heads of these individuals.\n",
    "cloak" : "You can't make out what kind of animal it was that gave them these monstorous cloaks or fur, but whatever it was...its big.\n",
    "gate" : "Its off to the west...where you came from.\n",
    "man" : "You try to talk to one of them, but they just turn away from you.\n",
    "men" : "You try to talk to one of them, but they just turn away from you.\n",
    "beards" : "You try to touch one of their beards and they slap your hand away.\n",
  ]));
reset();
}
