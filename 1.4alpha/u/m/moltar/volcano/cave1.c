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
The mouth of a cave which goes into a dormant volcano
which dwarves have begun to mine into 
MOLTAR
);
  set( "exits", ([
 "east" : AROOM+"cave2.c",
]) );
}
