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
The tourchlight flickers as you feel a draft from the  
south. The air grows more heted as you head southward
MOLTAR
);
  set( "exits", ([
"north" : AROOM+"cave16.c",
"south" : AROOM+"cave14.c",
]) );
}
