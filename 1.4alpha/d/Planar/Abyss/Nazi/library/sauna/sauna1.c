/*
** File: sauna1.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** Special thanks: To Cyanide for fixing my codes everytime
   They're messed up.
*/

#include "nazi.h"
#include <config.h>
#include <mudlib.h>

inherit SHOP;

void create()
{
    int i;

    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("restock_msg", wrap(
	/*
	"A tall man in a white uniform enters the locker room with a
	basket full of towels. He takes the used ones, and replaces 
	them with clean ones. He puts the used ones in the basket, 
	and then leaves."
	UNTERMINATED STRING    */
      ) );
    set( "short", "Sauna locker room" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
This is the locker room of the sauna. To the left you can find
several lockers for your belongings. Each locker has a number.
To the right is a pile of clean towels ready to be used. In
front of you is the door that gets you inside the sauna.
A sign hangs from the wall near the lockers.
EndText
    );
    set( "exits", ([
      "enter" : SAUNA+"sauna2.c",
      "east" : SAUNA+"massage.c",
    ]) );

    set( "item_desc", ([
      "lockers" : (@EndText
Each locker has a number. They go from 001 to 666. Read the sign to learn 
how to use them, and make sure you remember the number of the locker you
chose.
EndText
      ),
      "sauna" : (@EndText
To check the sauna, you have to enter it. A hint of how hot is inside 
there, is the steaming vapor coming out of the closed door. Are you sure
you want to get in there?
EndText
      ),

    ]) );

    // This is a loop that executes ten times. Each iteration of the loop
    // clones a locker, and sets all of it's number attributes.

    for (i=1; i<=10; i++) {
	string str;
	object locker;

	if (i < 10)
	    str = "00"+i;
	else
	    str = "0"+i;

locker = clone_object(NAZI_OBJ+"locker1.c");
	if (locker) {
	    locker->set("id", ({ "locker "+str, str }) );
	    locker->set_closed_long("This is locker #"+str+". It's closed.\n") ;  

	    locker->set("key", "sauna key "+str); 

	    locker->move(TO);
	} else {
	    tell_object( find_player("nsd"), 
	      "Locker object isn't loading.\n");
	}
    }
}

/* EOF */
