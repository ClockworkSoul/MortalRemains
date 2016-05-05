/*
** File: /u/n/nsd/library/cyberparty/sewer.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"
int rat_flag = 0;

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "Odd...");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
This room, contrary to the former one, makes you stress up.
Here you find a weird and strange kind of pool in the center of it.
It's a hole in the ground full of mud. The walls surrounding it
have grafitti, giving it the look of a New York alley.
You immediately want to leave this place as soon as possible.
EndText
    );
    set( "exits", ([
      "portal" : POOL+"pool.c",
      "down" : POOL+"sewer2.c",
    ]) );
    rat_flag = 0;
    set( "item_desc", ([
      "pool" : (@EndText
A hole in the ground full of mud. Big enough to cover the
whole center of the room. It's disgusting!  A lot of black furry
creatures emerge from it. You realize they are rats!!
EndText),
      "walls" : "The walls have 'grafitti'.\n",
      "grafitti" : (@EndText
A modern way of vandalizing private property, but still considered
art(cheap art, off course), made with spray paint.
You can see demons in this grafitti. Seems like these demons are
the logo of one of those weird street gangs.
EndText),
      "rats" : "Large rats, like those of New York alleys.\n"+
      "I would not 'watch' them longer if I was you!\n",
      "hole" : (@EndText
Looks like it was planned to have a pool constructed in it,
but somehow the work was never finished. It's full of mud,
and furry creatures that swim in it. You realize they're
rats...
EndText),
      "mud" : "Just mud filling up the hole!!\n",
      "room" : "Sighs... Why don't you just look around, dumb ass?\n",
    ]) );

    set("objects", ([
      " " : NAZI_MON+"mudrat2.c",
    ]) );
    reset();
}



void init() {
    add_action("watch_rats", "watch");
}

int watch_rats(string str) {
    object mudrat;

    if (!rat_flag) {
	for(int i = 0; i<5; i++) {

	    mudrat = clone_object(NAZI_MON+"mudrat.c");
	    mudrat->move(this_object());
	    mudrat->kill_ob(this_player());
	}
	write("The rats got mad and attack you!\n");
	say("A bunch of rats jump over "+TPN+" and bite "+POSS+"!\n");
	rat_flag = 1;
    }else
	write("Nothing but a bunch of corpses...\n");
    say(TPN+" looks at the corpses of rats...\n");
    return 1;
}
int reset() {
    rat_flag = 0;
    return ::reset();
}

/* EOF */
