#include "garden.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", " -{ CYANIDE }- ");
    set ("arena" ,1);
    set ("light", 1);
    set ("area_type", ([
      "green" : 2,
      "black" : 2
    ]) );
    set ("short", "A Beautiful Garden" );
    set( "long", @EndText
You are amazed as the sun strikes you in the face... Looking
about yourself, you find that you have emerged in a gigantic garden
deep beneath the surface of the earth. The sun strikes directly
downward from a gigantic aperture in the ceiling of this great
stone cavern. The sounds of strange and unusual beasts echo 
throughout the huge room. The you notice the plants...
  The many great trees and shrubs here are indeed beautiful to the
point of intoxication - but are also grotesque in the extreme. You
sicken as you realize that all around you the plants and wildlife
are twisted into obscene mockeries of nature.
EndText
    );
    set( "exits", ([
      "west" : MAZE+"/gard_entrance.c",
      "north" : GARDEN+"/clearing01.c",
      "east" : GARDEN+"/path.c",
      "south" : GARDEN+"/garden03.c"
    ]) );
}
