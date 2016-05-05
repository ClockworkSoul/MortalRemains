#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;
void create()
{
object CookieMonster;   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Shya's workroom");
    set( "long", @EndText
This small workroom is a mess.  
A desk set along the wall covered in papers, 
a lamp and a mixture of poems and codes.
Bookshelves galore surround this tiny room.  
The open window across the room gives a nice view. 
When it is time for Shya to relax after a long day 
of coding she goes to her hottub.
EndText
    );
    set( "exits", ([
      "start" : "/d/Prime/Central/room/startroom",
      "bedroom" :"/u/s/shya/private/bedroom.c",
      ]) );
    set("item_desc", ([
    "bookshelves" : "All the books are well dusted and well used.",
    "chair" : "It seems very comfortable.",
    "lamp" : "A small kerosene lamp.",
    "desk" : "This small desk has a lamp on it and covered in papers.",
    "books" : "Poetry and code you take your pick which one to read.",
    "window" : "An open window with a view of the ocean down below."
]));
CookieMonster=clone_object("/u/s/shya/CookieMonster.c");
CookieMonster->move(TO);

    set("pre_exit_func", ([
      "start" : "handcuff_check",  
      "home" : "handcuff_check",
    ]) );
    reset();
}
int handcuff_check() {
    if (present("handcuffs", TP)) {
	write("There is only one place for you to go while Shya's"+
	  " prisoner.  You remain where you were.\n");
	return 1;
    }
    else {
	return 0;
    }
}

void init ()
{
write("A Cookie Monster tosses his cookies all over you.\n");
say("A Cookie Monster tosses his cookies all over " + TPN + ".\n", TP);
::init();
}



