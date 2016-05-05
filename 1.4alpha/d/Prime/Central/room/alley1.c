#include <mudlib.h>
#include "central.h"

inherit ROOM;
void create(){
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set( "short", "Dark alley" );
    set( "long", @EndText
Two buildings stand to either side of this tight alley. Bags of
garbage are piled high against the walls. Parts of the walls
have been corroded by the constant chemical trash which is left
here.
EndText
    );
    set("author", "cyanide");
    set( "item_desc", ([
      "buildings" : "They are old and crumbling.\n",
      "garbage" : "It is damp and smelly.  What did these people throw away!?\n",
      "walls" : "An old brick construction of the 20th century.\n",
    ]) );
    set( "exits", ([
      "east"  : M_ROOM+"alley2.c",
      "west"  : M_ROOM+"road14.c",
    ]) );
    set("objects", ([ "punk" : M_MON+ "punk" ]) );
    reset();
}
