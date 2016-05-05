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
  "green" : 1,
  "black" : 2
  ]) );
  set ("short", "Garden Clearing");
  set( "long", @EndText
  A generic room in the Obscene Garden of Thylassa
EndText
  );
  set( "exits", ([
"north" : GARDEN+"/garden02.c",
"east" : GARDEN+"/aby_view.c",
"south" : GARDEN+"/garden03.c",
"west" : GARDEN+"/behind_tower.c",
  ]) );
}
