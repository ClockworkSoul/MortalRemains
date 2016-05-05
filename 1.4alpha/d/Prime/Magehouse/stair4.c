#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "Staircase" );
    set( "long", @EndText
This beautifully carved, wide wooden staircase seems to be
the only one in the house. The wood shines as if waxed on a
regular basis.
EndText
    );

    set( "exits", ([
      "up" : N_ROOM+"stair3.c",
      "east" : N_ROOM+"basement.c",
    ]) );

    set("objects",([
      "mage" : "/d/Prime/Magehouse/monsters/mage12.c",
    ]) );
    
    set("pre_exit_func", ([
        "up" : "mage_check",
        "east" : "mage_check",
    ]) );
    reset();
}

int mage_check() {
    if (present("mage", TO)) {
        write("The mage blocks your way! He would rather give his life "+
              "than let you pass.\n");
        return 1;
    }
else {
    return 0;
}
}
