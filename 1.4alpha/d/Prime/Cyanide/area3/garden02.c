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
set ("short", "Underground Garden" );
  set( "long", @EndText
The sun shining down in to the cavern stuns you still,
dazzling in your eyes and making your vision waver. The
humidity strikes you suddenly, making you begin to perspire
slightly. The sunlight filters through the trees, gently
caressing your face, slightly easing you discomfort.
   Trees fruited with many intoxications overhang your path, and
flowers bow obsequiously as you pass. An inch above the ground,
dull as agates, the eyes of mandrakes follow your tread.
EndText
  );
  set( "exits", ([
"east" : GARDEN+"/garden04.c",
"west" : GARDEN+"/path.c",
"south" : GARDEN"/clearing02.c"
  ]) );
}
