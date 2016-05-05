/*
** File: seeliecourt1.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

int active_flag = 0;
mapping faerie_map = ([]) ;

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
      "east" : ARV_ROOM+"seeliecourt3.c",
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
    if (!active_flag) {
	call_out("do_ring_func", 5);
	active_flag = 1;
    }
    if (!faerie_map[TP->query("name") ])
	faerie_map[TP->query("name") ] = 1;
}
void do_ring_func() {
    object user;
    string *names, msg;
    int i, size, val;
    names = keys( faerie_map );
    size = sizeof(names);
    for (i=0; i<size; i++) {
	user = find_player( names[i] );
	if (!user || environment(user) !=TO) {
	    map_delete(faerie_map, names[i]);
	    continue;
	}
	switch( faerie_map[ names[i] ]) {
	case 1 : msg = "Out of nowhere, a bunch of faeries appear...\n"; break;
	case 2 : msg = "The faeries make a circle around you...\n"; break;
	case 3 : msg = "They start to dance and play strange tunes...\n"; break;
	case 4 : msg = "You realize you're stepping in a faerie ring.\n"; break;
	case 5 : msg = "Suddenly you shrink from your original height!\n"; break;
	case 6 : msg = "You feel drowsy and dizzy...\n"; break;
	case 7 : msg = "All the trees seem giant to you now...\n"; break;
	case 8 : msg = "The faeries vanished from sight!\n"; break;
	case 9 : msg = "You can inhabit the trees now.\n"; break;
	default : msg = "Move or you will die!!!!!!\n";
	    user->receive_damage(user->query_level()*1, "necromancy");
	    break;
	}
	faerie_map[ names[i] ] ++;
	tell_object(user, msg);
    }
    if (sizeof(keys(faerie_map)))
	call_out("do_ring_func", 5);
    else
	active_flag = 0;
    return;
}
/* EOF */
