#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "bouncer" : MON+"bouncer.c" ]) );
  reset();
  set( "light", 1 );
  set( "short" , "Club Confetti");
  set( "long" , @EndText
  You have wandered into Club Confetti. Lasers and smoke fill the room,
  loud crashing music and a pumping beat send shivers through your spine
  everything seems to be shaking. The lighting in here isn't too great
  but you can make out people and bouncers. Off to the east there is a
  small bar, with what looks like an ex-WWF wrestler behind it.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street17.c",
    "east" : PUBS+"pub2.c",
  ]) );
  set("item_desc" , ([
    "bouncers" : "Large men wearing black uniforms with the words Club Confetti on the back.\n",
    "lasers" : "Don't worry, its just for show.\n",
    "smoke" : "Thick white clouds of smoke billowing out from the smoke maker.\n",
    "wrestler" : "You can't see him very well from here.\n",
    "bar" : "You can't see it very well from here.\n",
  ]));
}
