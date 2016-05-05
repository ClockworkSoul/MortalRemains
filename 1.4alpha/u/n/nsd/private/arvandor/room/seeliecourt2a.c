/*
** File: seeliecourt2a.c
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
    set("short", "Pathway to Seelie Court");
    set( "long", @EndText
The path to the seelie court continues to the east. The grass
here is extremely and strangely green. To the north, there's a
cottage. To the east is a big and weird oak tree.
EndText );
    set( "exits", ([
      "west" : ARV_ROOM+"seeliecourt1.c",
      "north" : ARV_ROOM+"seeliecourt4.c",
    ]) );
    set("item_desc", ([
      "grass" : "Bright green grass. This is not normal...\n",
      "cottage" : "It's surrounded of ivys, but still vissible.\n",
      "tree" : "What tree you wish to see?\n",
      "oak tree" : "Looks weird from here. Go east for a closer view.\n",
    ]) );
}
void init () {
    call_out("do_ring_func", 20, TP);
}
int do_ring_func( object ob ) {
    if (environment(ob) != TO) return 0;
    tell_object(ob,
      "You feel drowsy and dizzy as you return to your original height.\n");
    ob->receive_damage(ob->query_level()*1, "necromancy");
    call_out("do_ring_func",20, ob);
    return 1;
}
/* EOF */
