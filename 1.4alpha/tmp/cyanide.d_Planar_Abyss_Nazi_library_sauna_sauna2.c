/*
** File: sauna2.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** (Cyanide helped a little. :)   11 April 2000)
*/

#include "/u/c/cyanide/debug.h"
#include <config.h>
#include <mudlib.h>
#include "nazi.h"

inherit ROOM;

int active_flag = 0;
mapping sauna_map = ([]);

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Sauna");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
You enter a small cabin with enough space for ten persons at once.
The temperature is comfortable to your skin. There's one long
bench to your left, and another to your right. You prepare yourself
for a steaming experience. But beware of staying too long!
Who knows what can happen...
EndText
    );
    set( "exits", ([
      "out" : SAUNA+"sauna1.c",
    ]) );
    set( "item_desc", ([
      "benches" : "Wooden benches, Long enough for "+
      "five persons each.\n",
    ]) );
}

void init() {
    if (!active_flag) {
	call_out("do_steam_func", 30);
	active_flag = 1;
    }

    // This keeps track of everbody who comes and goes.
    if (!sauna_map[ TP->query("name") ])
	sauna_map[ TP->query("name") ] = 1;
}

void do_steam_func() {
    object user;
    string *names, msg;
    int i, size, val;

    names = keys( sauna_map );
    size = sizeof(names);

    for (i=0; i<size; i++) {
	user = find_player( names[i] );
	if (!user || environment(user) != TO) {
	    map_delete(sauna_map, names[i]);
	    continue;
	}

	switch( sauna_map[ names[i] ] ) {
	case 1 : msg = "Suddenly you feel strange...\n"; break;
	case 2 : msg = "You sweat like never before.\n"; break;
	case 3 : msg = "Your skin is evaporating...\n"; break;
	case 3 : msg = "You're draining...\n"; break;
	case 4 : msg = "Your pressure increases...\n"; break;
	default : msg = "Your blood is boiling...\n";
	    user->receive_damage(user->query_level(), "fire");
	    break;
	}

	sauna_map[ names[i] ] ++;
	tell_object(user, msg);
    }

    if (sizeof(keys(sauna_map)))
	call_out("do_steam_func", 30);
    else
	active_flag = 0;

    DEBUG("Size = "+sizeof(keys(sauna_map))+"\n");
    return;
}

/* EOF */
