/*
** File: /u/n/nsd/library/library.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** Special thanks: To the best admin. Cyanide, for his patience
teaching me easy and dificult codes step by step.
*/

#include "nazi.h"
#include <config.h>
#include <mudlib.h>

int monster_flag;

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "Red Library" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
This is an ancient room decorated Shakespeare's style.
It's called the Red Library because all the books in it
are binded with blood-tinted leather. The bookcases are
crowded of these books from top to bottom. perhaps this 
is the right moment to start your passion for reading...
EndText
    );
    // Cy, hon; there must not be obvious exits from the library.
    //the only way out is through the books. There's one called
    // 'Start' :-)
    set( "exits", ([
    ]) );
    set( "item_desc", ([
      "books" : (@EndText
They're locked inside the bookcases.
EndText
      ),
      "bookcases" : (@EndText
Dark oak medieval bookcases. Each one has 
two glass doors, which are closed to prevent the rare
collection from aging. There are five bookcases. 
Try looking at them one by one.
EndText
      ),

      "bookcase 1" : (@EndText
This bookcase has been locked for so long. It has 
spider webs hanging from the glass doors. The
books in there seem to be written in greek 
because of the titles. The bindings are dark
red (old blood coagulated for centuries).
EndText
      ),

      "bookcase 2" : (@EndText
This one is a little tattered, giving you an idea 
of how antique it is. You prefer not to touch it
fearing it could crumble to dust...
EndText
      ),

      "bookcase 3" : (@EndText
This bookcase has a strong rare scent, which
is hard to identify. One of the glass doors is
shattered, and little dusted. You will sneeze 
if you keep on looking at it.
EndText
      ),

      "bookcase 4" : (@EndText
 Like the other three, this one is locked too.
 Through the glass doors, you can see the bindings
are bright red (fresh blood). A chill goes up your
spine when you notice the titles are players'
names. It scares the hell out of you, making you 
go better to the next bookcase.
EndText
      ),

      "bookcase 5" : (@EndText
You find an open bookcase. Seems like someone 
was here recently. You have access to these
books. You find several interesting titles. To see
what they are about, 'browse' the 'titles'. 
Good luck!!!
EndText
      ),
    ]) );
    monster_flag = 1;
}


void init() {
    add_action("browse_titles", "browse");
    add_action("read_func", "read");
}

int browse_titles (string str) {
    if (!str || str!="titles") {
	write("Browse what?\n");
	return 1;
    }

    say(TPN+" browses various titles from the rare collection.\n");
    write(@EndText
This is the list of some weird titles printed in the cover
of the books. Some are in foreign languages, and they don't
appear in the list. You can 'read' <bookname> to check one.
Choose your titles carefully, for they could be the last...

*Pool party
*World War II
*Start
*Suite Lust
*Book Binding
EndText);
    return 1;
}

int read_func(string str) {
    object monster;
    string room = "unknown";

    if (!str) {
	write("What book would you like to read?\n");
	return 1;
    }

    str = lower_case(str);
    switch(str) {
    case "world war ii" :
	room = NAZI_ROOM+"nazi1.c"; break;

    case "pool party" :
	room = LIBRARY+"cyberparty/pool.c"; break;

    case "start" :
	room = START; break;

    case "suite lust" :
	room = LIBRARY+"lust/suite.c"; break;

    case "sauna inferno" :
	room = LIBRARY+"sauna/sauna1.c"; break;

    case "book binding" : 
	monster = clone_object(NAZI_MON+"binder.c");
	if (monster && monster_flag) {
	    say("As "+TPN+" opens a book, a demon leaps out!\n");
	    write("Suddenly, the Book Binder Demon jumps out of the book!\n");
	    monster->move( this_object() );
	    monster->kill_ob( this_player() );
	    monster_flag = 0;
	} else
	    write("An awful scent of death comes from this book "+
	      "as you read it...\n");

	return 1;
    }

    if (room != "unknown") {
	say(TPN+" opens a book and reads it.\n"); 
	TP->move_player(room);
    } else {
	write("You don't see that book here.\n");
    }

    return 1;
}
void fix_flag() { monster_flag = 1; }

/* EOF */
