
#include <mudlib.h>
#include <config.h>
#include <kyrie.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("objects",(["bear" : "/d/Prime/Kyrie/monsters/bear.c"]) );
    reset();
    set("author","spooner");
    set( "light", 1 );
    set( "short" , "Northern Cavern" );

    set( "long", @EndText
This is the Throne of a Huge Bear.  You notice that the 
Bear is licking his chops at the sight of you.  You really 
feel uncomfortable here.  There are some torches on the
walls.  There is also a huge pile of bones and carcasses.
EndText
    );

    set("item_desc", ([
      "torches" : "There are many torches here to keep the throne very well lit.\n",
      "throne" : "A large throne made of bones, large enough for the 9foot tall bear that resides in this cavern.\n",
      "bones" : "As you look at the bones you notice the remain of some of your friends.\n",
    ]) );

    set( "exits", ([
      "south" : KYRIE+"kyrie4.c",
    ]) );
}
