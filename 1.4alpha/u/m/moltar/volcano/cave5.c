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
You have entered a hallway of a mine shaft. You are 
lucky that the hallways are tourch lit
MOLTAR
);
  set( "exits", ([
"south" : AROOM+"cave16.c",
"east" : AROOM+"cave3.c",
"east" :  AROOM+"cave3.c"
]) );
}
