#include <config.h>
#include <mudlib.h>
#include "volcano.h"
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
        set("light",1 );
        set("short", "Standard ROOM");
        set("long", @MOLTAR      
MOLTAR
);
  set( "exits", ([
"east" : AROOM+"cave10.c",
"west" : AROOM+"cave12.c",
]) );
}
