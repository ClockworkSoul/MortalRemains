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
The mine shaft goes on and on its more humid here and 
the stench of slupher grows stronger as you continue
MOLTAR
);
  set( "exits", ([
"west": AROOM+"cave4.c",
"east" : AROOM+"cave7.c",
]) );
}
