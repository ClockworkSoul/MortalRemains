inherit ROOM;

#include "sophia.h"
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "A train platform" );
set("long",wrap(
"You have stepped onto what is laughingly called a train platform "+
"A few planks lead towards a train deserted except for the engineer and "+
"his stoker.  Armor plating is all that adorns this conveyance. "+
"You feel a slight chill run up your back as you contemplate what you "+
"have paid in hard earned credits to experience."
));
    set( "exits", ([
"station" : "/u/s/sophia/pad1.c",
    ]) );
    set("item_desc", ([
      "sand" : "hot and black.\n",
    ]) );
}
