#include <config.h>
#include <mudlib.h>
#include "volcano.h"
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
        set("light",1 );
        set("short", "Into the Darkness");
        set("long", @MOLTAR      
Walking downward into the cave, the light grows dimmer
upon aproaching the edge of a mine shaft going 
downward into darkness
MOLTAR
);
  set( "exits", ([
  "west" : AROOM+"cave1.c",
  "down" : AROOM+"cave3.c",
]) );
}
