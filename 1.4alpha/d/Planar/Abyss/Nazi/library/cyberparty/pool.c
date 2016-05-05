/*
** File: /u/n/nsd/library/cyberparty/pool.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** Special thanks: To Dalceon for helping me code the action
** for the punks. He rocks!!!
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"

int punk_flag = 0;

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "The Relaxing Room" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", "@@query_long");
    set( "exits", ([

    ]) );

    punk_flag = 0;

    set( "item_desc", ([
      "pool" : wrap("A swimming pool. Big enough to make a party with "+
	"all your friends. Seems relaxing. A ladder in front of you leads "+
	"you into it. A diving board is at the other extreme of the pool."),
      "water" : "The water is comfortably warm. Nice enough to 'swim' "+
      "or 'float' in.\n",
      "walls" : "The walls have 'frescoes'.\n",
      "frescoes" : wrap("Antique styled plaster paintings of angels. "+
	"Definitely an expensive work of art. The angels seem to "+
	"observe you."),
      "ladder" : wrap("A pool ladder. You can either 'climb down' to get "+
	"into the pool, or 'climb out' to get out.\n"),
      "board" : "A nice olympic diving board. Try 'jump board' to use it.\n",
      "angels" : wrap("Congrats! You have found a secret portal that will get you "+
	"into another room. 'Look at portal'."),
      "portal" : wrap("Almost invisible. Type 'open portal', and then 'enter "+
	"portal'. You'll have an unforgettable experience..."),
    ]) );

}


void init() {
    add_action("jump_board", "jump");
    add_action("climb_down", "climb");
    add_action("climbout", "climbout");
    add_action("swim", "swim");
    add_action("do_float", "float");
    add_action("open_portal", "open");
    add_action("enter_portal", "enter");
}

string query_long() {
    string str = (@EndLong
You have entered the Relaxing Room. Here you find a large pool in the
center of it. The pool has the shape of a giant seashell. The walls
surrounding it have frescoes imitating some Michaelangelo's paintings. You
feel tempted to swim a little.
EndLong
    );

    if (punk_flag)
	str += "There is a portal here, waiting for you to enter it.\n";

    return str;
}

int jump_board(string str) {
    if(!str || str!="board") {
	write("Jump what?\n");
	return 1;
    }
    say(TPN+" gives an olympic jump on the diving board and "+
      "splashes into the water... WOO WOO!!!\n");
    write(
      wrap("You jump on the diving board and splash into the "+
	"water... ouch! That must hurt."));
    return 1;
}

int climb_down(string str) {
    if(!str) {    
	write("Climb where?\n");
	return 1;
    }

    if (str=="down") {    
	say(TPN+" climbs down the ladder, and gets in the pool.\n");
	write("As you climb down the ladder, the warm water covers "+
	  "your skin.\nAhhhh...delicious!\n");
    }

    if (str=="out" || str=="up") { 
	say(TPN+" climbs up the ladder and exits from the pool.\n");
	write(
	  "You climb up the ladder and exit from the pool.\n"+
	  "You spill drops of water all around the border.\n");
    }

    return 1;
}

int climbout(string str) {
    return 1;
}

int swim(string str) {
    say(TPN+" swims in the pool and teases you to do the same.\n");
    write(wrap(
	"You swim in that magnificent warm water that relaxes "+
	"your body immediately. Right now, you are the envy of "+
	"those who are watching."));
    return 1;
}

int do_float(string str) {
    say(TPN+" floats like a swan.\n");
    write("You float on that water that has soothe your tensions and "+
      "your limbs... \nYou don't want to leave, not yet...\n");
    return 1;
}

int enter_portal(string str) {
    if (!punk_flag) {
	write("It's not even open!\n");
	return 1;
    }

    write("You get teleported to a similar room, but it's the wicked "+
      "version of it.\n");
    say(TPN+" dissappears through a secret door.\n");
    this_player()->move_player(POOL+"sewer.c"); 
    say(TPN+" appears from the secret passage.\n");
    return 1;
}

int open_portal(string str) {    
    object punk;

    if (!punk_flag) {    // if punk_flag = 0, basically
	for(int i = 0;i<5;i++) {    
	    punk = clone_object(NAZI_MON+"punk.c");
	    punk->move(this_object());
	    punk->kill_ob(this_player());
	}
	write("You open the portal, and five punks attack you!\n");
	say(wrap("As "+TPN+" opens the portal, a gang of five punks "+
	    "come in and attacks "+ objective(TP->query("gender"))+"!"));
	punk_flag = 1;
    }else
	write("You open the portal...  Now enter it!\n");
    return 1;
}

int reset() {
    punk_flag = 0;

    return ::reset();
}

/* EOF */
