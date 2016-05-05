/*
** File: seeliecourt4.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the cottage");
    set( "long", @EndText
You're inside a small cottage. It's warm and inviting. A
long table lies to one of the corners. Some ivies and
microscopic plants have grown on the walls. It's a little
dark in here, except for a candle that's lit on the table.
EndText );
    set( "exits", ([
      "south" : ARV_ROOM+"seeliecourt2b.c",
    ]) );
    set("item_desc", ([
      "table" : "A long table crowded of crystal vials full of potions.\n"+
      "A candle lies to one of it's corners.\n",
      "candle" : "The candle is almost extinguished. Completely melted,\n"+
      "but still lit and bright. Odd but true!\n",
      "vials" : "Crystal vials full of colored potions.\n",
      "walls" : "They look unattended. Ivy and microscopic plants have\n"+
      "made their way on them.\n",
      "ivy" : "Nothing more than common forest ivy.\n",
      "plants" : "Green stains on the walls. Just bunches of tiny plants.\n",
    ]) );
    set("listen",
    );
}

/* EOF */
