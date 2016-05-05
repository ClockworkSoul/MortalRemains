#include <config.h>
#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("short", "Hallway" );
    set( "long", @EndText
You are at the terminus of a short hallway. It would seem that
there are two choices for you here: down a flight of stairs
directly to your south, or down a small side passage to the.
southeast. There seems to be what resembles a message in blood
on the wall here.
The tunnel to the southeast seems to have been collapsed by
some force. The sign on the rubble says "Will be open
eventually..."
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/hallway2.c",
      "south" : MAIN+"/infstair.c",
    ]) );
    set ("item_desc", ([
      "message" : iwrap("It reads, 'Newbies there!' and an arrow "+
	"pointing southeast."),
      "stairs" : iwrap("They seem dark and steep, only meant for"+
	" higher level players (Hint!)"),
    ]) );
}

void reset()
{
    object sign;
    ::reset();
    seteuid( getuid());
    if(present("sign",this_object())) return;
    sign=clone_object(OBJ+"/sign01.c");
    sign->move(this_object());
}
