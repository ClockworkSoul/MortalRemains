#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Abbey Road");
    set( "long", @EndText
You are walking on what used to be a cobblestone walkway. Further 
to the east you can see the remains of an old Abbey. The walkway
leads back west to the main road. The walls of the town guard your
passage to the north, while the backs of buildings are to the south.
EndText
    );
    set( "exits", ([
     "west" : RM+"AR2.c",
    "east" : RM+"AR4.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "buildings" : "Just the backs, nothing of note.\n",
     "walls" : "Cracked and weatherbeaten, they house the town.\n",
     "cracks" : "Nothing of importance.\n",
     "cobblestones" : "They have seen better days.\n",
     "walk" : "You're on it, though it seems to be quite worn.\n",
     "abbey" : "An old Abbey, hardly standing, to the east.\n",
    ]) );
}
