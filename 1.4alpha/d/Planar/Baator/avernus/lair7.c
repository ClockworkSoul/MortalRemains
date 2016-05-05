#include <config.h>
#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short", "The Lair of the Queen of Dragonkind");
    set ("long", @EndText
You are in a massive cave complex illuminated by torches fixed to the 
cavern walls. Strangely there are no dragons in here, and the acrid smell
is much less potent. A large portal is in the center of the room, through
which you can see the city streets of your origin!
EndText
    );
    set ("exits", ([
      "east" : BAATOR+"avernus/lair8.c"
    ]));
}

void init() {
    add_action("enter", "enter");
}

int enter ( string str ) {
    write("You step into the portal...\n");
    say(TPN+" steps into the portal and dissapears!\n");
    TP->move_player(START, "SNEAK");
    say(TPN+" appears in a burst of smoke, looking somewhat confused.\n");

    return 1;
}

/* EOF */
