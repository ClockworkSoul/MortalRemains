#include <config.h>
#include <mudlib.h>
#include "volcano.h"
inherit ROOM;

void create()
{
::create();
seteuid(getuid());
        set("light",1 );
        set("short", "Entrance to Darkness");
        set("long", @MOLTAR      
At the bottom of a well constructed mine shaft. The 
light of day slowly fades from view and the dim light 
the tourches flickers slowly with the breese
MOLTAR
);
  set( "exits", ([
"east" : AROOM+"cave4.c",
"west" : AROOM+"cave5.c",
"up" :AROOM+"cave2.c",
]) );
}
