#include <config.h>
#include <mudlib.h>
#include "volcano.h"
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
        set("light",1 );
        set("short", "In the Mine Shaft");
        set("long", @MOLTAR      
You are inside a mine. Tourches line the walls
of this damp passageway
MOLTAR
);
  set( "exits", ([
"west" : AROOM+"cave3.c",
"east" :AROOM+"cave6.c",
]) );
}
