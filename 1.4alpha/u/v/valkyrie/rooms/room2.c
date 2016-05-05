#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    object chest, tmp;

    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "blood");
    set("objects",(["mage" : "/d/Prime/Magehouse/monsters/mage1.c"]) );
    reset();
    set( "short", "House of the Mage");
    set( "long",@EndText
As you enter this room, the most striking thing that is here is the large
chest in the center of the room. It occurs to you that if you could find
the key to it, you would be rewarded with many things. The only other
noteworthy features of the room are the door leading back to the south, 
and the other to the east.
EndText
    );
    set( "exits", ([
      "east" : N_ROOM+"room3.c",
      "south" : N_ROOM+"room1.c",
    ]) );
    set( "item_desc", ([
      "chest" : "Your hopes fade when you notice it has seven "+
      "different keyholes.\n",
      "center" : "That's where the chest is.\n",
      "doors" : "They lead south and east.\n",
    ]) );
    chest = clone_object("/obj/obj/chest.c");
    clone_object(N_ARM+"robes.c")->move(chest);
    clone_object(N_ARM"ddbracers.c")->move(chest);
    chest->toggle_closed();
    chest->move(TO);
}

/* EOF */
