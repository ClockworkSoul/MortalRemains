#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "Ackmad's Armor");
   set("long", @LickMyAssHole
This is a fucking bullshit armour shop, nothings here.
Suck it up, I'll fix when i want to.
LickMyAssHole
);
  set( "exits", ([
          "west" : AROOM+"street12.c",
  ]) );
}
