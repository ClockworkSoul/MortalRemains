#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
set("item_desc", ([
"sign"  :  "                     \n"+
"     _____________________    \n"+
"     |                    |     \n"+
"     |     The Town of    |     \n"+
"     |      Tantallon     |     \n"+
"     |                    |     \n"+
"     |     Population:    |     \n"+
"     |    Noone knows,    |     \n"+
"     |    Noone cares..   |     \n"+
"     |                    |     \n"+
"     |____________________|     \n"+
"              |   |          \n"+
"              |   |          \n"+
"              | | |          \n"+
"              |   |          \n"+
"              |   |          \n"+
"   ___________|   |__________     \n"+
"   |                        |\n"
])  );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Northern Bayside Road" );
    set( "long", @EndText
You have entered the town of Tantallon.  There is a sign here just waiting 
for someone to take a look at it.  The town continues south.
EndText
    );
    set( "exits", ([
"north"  :  "/u/a/abyss/town/tb.c",
     "south"  :  "/u/a/abyss/town/t2.c",
    ]) );
}
