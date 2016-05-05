inherit ROOM;

#include "garden.h"

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", " -{ CYANIDE }- ");
    set ("arena" ,1);
    set ("light", 1);
    set ("short", "Abyss View");
    set( "long", @EndText
  A generic room in the Obscene Garden of Thylassa
EndText
    );
    set( "exits", ([
      "west" : GARDEN+"/garden03.c",
      "northwest" : GARDEN+"/clearing02.c",
      "down" : "/d/Outer/layer1/kfffsd.c",
    ]) );
}
