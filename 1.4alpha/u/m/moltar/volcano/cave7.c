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
"west" : AROOM+"cave6.c",
"south" : AROOM+"cave8.c",
]) );
}
