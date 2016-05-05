#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Crest Road");
    set( "long", @EndText
You are walking along Crest Road, it's the main road in Hill Vally.
To the south is the town square, while further north you can see
the town walls. To the east is a small butcher shop, while west is
a weapon and armour shop.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm7.c",
     "north" : RM+"rm9.c",
     "east" : RM+"bucher.c",
     "west" : RM+"weapon_shop.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "town square" : "To the south, you real close to it.\n",
     "square" : "To the south, your real close to it.\n",
     "bucher" : "Looks like they might sell meat.\n",
     "bucher shop" : "Looks like they might sell meat.\n",
     "weapon and armour shop" : "Looks like they sell stuff.\n",
     "weapon shop" : "Looks like they sell stuff.\n",
     "armour shop" : "Looks like they sell stuff.\n",
     "shop" : "Which one, bucher or weapon?\n",
     "stuff" : "It's in the stores, you can't really see from here.\n",
     "meat" : "Yummy, might not be in the weapon shop, bucher for sure.\n",
    ]) );
}
