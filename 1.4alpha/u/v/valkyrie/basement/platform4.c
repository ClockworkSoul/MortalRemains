#include <config.h>  
#include <mudlib.h>
#include "basement.h"

inherit ROOM;
    
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("objects", ([
"gnome supervisor" : "/d/Prime/Magehouse/monsters/gnome3.c"
]) );
    reset();
    set("author","blood");
    set( "short", "Platform" );
    set( "long", @EndText
This is a small open platform which allows the supervisors to
watch over the work of the worker gnomes.
EndText
    );
    set( "exits", ([ 
      "east" : BSMNT+"gcamp10.c",
    ]) );
}
