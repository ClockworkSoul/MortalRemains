#include <config.h>
#include <mudlib.h>
#include "volcano.h"
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
        set("light",1 );
        set("short", "Mine Shaft");
        set("long", @MOLTAR      
The mine shaft seems to go on ward forever there
is no trace of daylight here as the dim light
from the tourches flicker
MOLTAR
);
  set( "exits", ([
"north" : AROOM+"cave5.c",
"south" : AROOM+"cave15.c",
]) );
}
