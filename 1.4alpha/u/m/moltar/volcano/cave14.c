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
The walls of this chamber reveal a vien of sulpher 
in the rock structure. Steam gushes from several cracks
in the walls
MOLTAR
);
  set( "exits", ([
"north" : AROOM+"cave15.c",
"east" : AROOM+"cave13.c",
]) );
}
