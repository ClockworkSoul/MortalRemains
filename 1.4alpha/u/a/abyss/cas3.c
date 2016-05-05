#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "The Abyss" );
    set( "long", @EndText
You seem to be falling in what seems to be "The Abyss" but you are not sure.
The room is pitch black except for the faint light coming from your
imagination of what the room looks like.  There is a desk in what seems to 
be the corner, and on the side of it there is a cooler with some assorted
sodas in it(you can barely make out what seems to be a few bottles of Corona
underneeth all the soda). There are a few chairs scattered around the
room.  On some are magazines, books, cards, and pets.  The others are free
for you to sit in.  Now that your eyes have adjusted to the dim light you
can barely make out some pictures of family and pets.  There is a sign
that reads "DO NOT DISTURB ME IF I AM WORKING!!"
EndText
    );
    set( "exits", ([
      "start" : START,
"nsd"  :  "/u/n/nsd/workroom.c",
      "void"  : VOID,
    ]) );
}
