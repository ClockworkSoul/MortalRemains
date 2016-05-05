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
    set ("short", "Underground Garden");
    set( "long", @EndText
The organic scents of a humid forest in full bloom swim in
your nostrils with a mixed pungency of natural wilderness and a
stench of something unnatural.
   About you in this area, bushes and shrubs blooming with the
disembodied hands and ears of young girls surround you -
seemingly reaching out to you, begging for some kind of mercy.
Ladies' lips on long climbing vines begin making hungry sucking
noises at your approach, as if expecting you to feed them. Judging
from the vivid red of their blooms, live blood apparently flows
through their petals.
EndText
    );
    set( "exits", ([
      "north" : GARDEN+"/clearing02.c",
      "northwest" : GARDEN+"/s_of_tower.c",
      "west" : GARDEN+"/garden01.c",
    ]) );
}
