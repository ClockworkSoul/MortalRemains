#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit PUB;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "jerry" : MON+"jerry.c" ]) );
  reset();
  set( "light", 1 );
  set( "short" , "The Viper Room");
  set( "long" , @EndText
  This is the back bar, probably more commonly known as the Viper Room.
  Behind the bar stands what looks to be an ex-WWF wrestler, all along
  the sides of the bar stand girls in small mini-skirts, and all of
  the punks that are trying to pick them up. The lighting in this room
  isn't that much better, but the pounding music seems to have settled
  a little, and now just comes from a tierd old jukebox in the corner.

  The commands are menu, buy <drink>, and powerheal <drink>.

EndText
  );
  set( "exits", ([
    "west" : STREET+"pub1.c",
  ]) );
  set("item_desc" , ([
    "bar" : "Its a long bar, made from what looks to be shoddy playwood painted over in black.",
  ]));
}
