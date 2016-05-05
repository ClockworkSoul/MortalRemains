#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
set("short", "Black Lane");
  set( "long", @EndText
This is Black Lane, it leads into the slum area
of the city. You'd better watch your back.
EndText
  );
  set( "exits", ([
"east" : Oerth+"/rooms/blane2",
"west" : Oerth+"/rooms/proc1",
  ]) );
}
