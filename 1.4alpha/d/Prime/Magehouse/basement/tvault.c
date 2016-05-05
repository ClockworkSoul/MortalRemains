#include "basement.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "Treasure Vault" );
    set("objects", ([
        "mace" : "/d/Prime/Magehouse/weapons/mace.c",
        "staff" : "/d/Prime/Magehouse/weapons/staff.c",
        "sling" : "/d/Prime/Magehouse/weapons/sling.c",
        "sword" : "/d/Prime/Magehouse/weapons/vsword.c",
    ]) );
    reset() ;
    set( "long", @EndText
This large room is entirely carved from granite. Huge columns of
stone support the ceiling. It is obviously made to hold something
of great value,as the construction and design are impeccable.
EndText
    );
    
}  
