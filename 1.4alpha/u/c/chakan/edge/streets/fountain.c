#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
set( "short" , "Drinking well" );
  set( "long", @EndText
Ugly hooded water hole known as a well in the middle of the slums.
EndText
  );
  set( "exits", ([
	"northeast" : "/u/c/chakan/edge/streets/r29.c",
	"northwest" : "?",
	"southeast" : "?",
	"southwest" : "?",
	"north" : "/u/c/chakan/edge/streets/r30.c",
	"south" : "?",
	"east" : "/u/c/chakan/edge/streets/r28.c",
	"west" : "?",
  ]) );
}
