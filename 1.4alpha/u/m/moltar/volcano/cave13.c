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
Off in the distance you notice a river of molten rock
The heat grows stronger as you continue
Obviously this vololcano is not as dormant as would like 
to be thought previously
MOLTAR
);
  set( "exits", ([
"west" : AROOM+"cave14.c",
"east" : AROOM+"cave12.c",
]) );
}
